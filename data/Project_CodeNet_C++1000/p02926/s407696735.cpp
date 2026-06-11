#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef double ld;
ld PI=acos(-1),EPS=1e-15,a[100],b[100];
ld n,ans,A,B,L;
int main(void){
    cin>>n;
    //cout<<PI<<endl;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    for(int i=0;i<360;i++){
        A=0,B=0;
        L=(ld)((ld)i/180);
        //cout<<L<<endl;
        for(int j=0;j<n;j++){
            if(a[j]*cos(PI*L)+b[j]*sin(PI*L)>0){
                A+=a[j],B+=b[j];
            }
        }
        ans=max(ans,A*A+B*B);
    }
    cout<<setprecision(20)<<pow(ans,0.5)<<endl;
}
