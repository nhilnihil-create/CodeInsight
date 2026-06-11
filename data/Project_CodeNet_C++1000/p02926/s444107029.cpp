#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
ld n,s[100],t[100],x,y,a;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i]>>t[i];
    }
    for(int i=0;i<360;i++){
        x=0.0,y=0.0;
        for(int j=0;j<n;j++){
            if(cos(i*M_PI/180)*s[j]+sin(i*M_PI/180)*t[j]>0){
                x+=s[j],y+=t[j];
            }
        }
        a=max(a,x*x+y*y);
    }
    cout<<setprecision(15)<<sqrt(a)<<endl;
}