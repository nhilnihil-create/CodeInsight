#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    if(n>=100 && n<=599) ans=8;
    else if(n>=600 && n<=799) ans=7;
    else if(n>=800 && n<=999) ans=6;
    else if(n>=1000 && n<=1199) ans=5;
    else if(n>=1200 && n<=1399) ans=4;
    else if(n>=1400 && n<=1599) ans=3;
    else if(n>=1600 && n<=1799) ans=2;
    else if(n>=1800 && n<=1999) ans=1;
    cout<<ans<<"\n";
}