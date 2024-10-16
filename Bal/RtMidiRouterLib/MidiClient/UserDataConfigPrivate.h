#pragma once

#include <QObject>
#include <QObjectComputedProperty>
#include <QQmlEngine>

#include "Dropdownlist.h"
/*[[[cog
import cog
from UserDataConfigPrivate import classUserDataConfigPrivate


cog.outl(classUserDataConfigPrivate.getClassHeader(),
        dedent=True, trimblanklines=True)

]]] */
class UserDataConfigPrivate : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int activePresetID READ activePresetID WRITE setActivePresetID NOTIFY activePresetIDChanged )
    Q_PROPERTY(QString computerUuid READ computerUuid  CONSTANT )
    Q_PROPERTY(QList<QList<Dropdownlist *>> dropdownlists READ dropdownlists  NOTIFY dropdownlistsChanged )
    Q_PROPERTY(QString uniqueId READ uniqueId  NOTIFY uniqueIdChanged )
    Q_PROPERTY(QStringList virtualInPorts READ virtualInPorts  NOTIFY virtualInPortsChanged )
    
    QML_ELEMENT
public:
    UserDataConfigPrivate(QObject *parent = nullptr);
    virtual ~UserDataConfigPrivate() = default;

    
    
    int activePresetID() const{return m_activePresetID;} 
    
void setActivePresetID(const int newActivePresetID)
    {
        if (m_activePresetID == newActivePresetID)
            return;
        m_activePresetID = newActivePresetID;
        emit activePresetIDChanged();
    }


    
    QString computerUuid() const{return m_computerUuid;} 
    

    
    QList<QList<Dropdownlist *>> dropdownlists() const{return m_dropdownlists;} 
    

    
    QString uniqueId() const{return m_uniqueId;} 
    

    
    QStringList virtualInPorts() const{return m_virtualInPorts;} 
    


signals:
    void activePresetIDChanged();
    void dropdownlistsChanged();
    void uniqueIdChanged();
    void virtualInPortsChanged();
    

protected:
    QString m_computerUuid;
    QList<QList<Dropdownlist *>> m_dropdownlists;
    QString m_uniqueId;
    QStringList m_virtualInPorts;
    

private:
    int m_activePresetID;
    
    void ctorClass();
};

//[[[end]]]
