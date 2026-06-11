#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string t;
    cin>>t;
    if(t[0]=='?'){
    if(t[1]=='D')
        t[0]='P';
    else
        t[0]='D';
     }  
    for(int i=1;i<t.length();i++)
    {
        if(t[i]=='?'){
            if(t[i-1]=='P')
                t[i]='D';
            else if(t[i+1]=='D' &&  t[i+1]=='D')
                 t[i]='P';
            else  if(t[i-1]=='D' && (t[i+1]=='P' || i==t.length()-1 || t[i+1]=='?'))
                t[i]='D';
            
            
           }
   }
    cout<<t;               
}
