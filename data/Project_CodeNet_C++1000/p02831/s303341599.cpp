#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    ll A,B;
    cin>>A>>B;
map<ll,ll> Ae,Be,Ce;
    
    ll x=2,y=2;
    while(A!=1){
        if(A%x==0){
            Ae[x]++;
            Ce[x]++;
            A/=x;
        }else{
            x++;
        }
    }
    
    while(B!=1){
        if(B%y==0){
            Be[y]++;
            Ce[y]++;
            B/=y;
        }else{
            y++;
        }
     }
    ll sum=1;
    for(auto p:Ce){
        auto k=p.first;
        Ae[k]=max(Ae[k],Be[k]);
    }
    for(auto p:Ae){
        auto k=p.first;
        auto v=p.second;
        sum*=pow(k,v);
    }
    cout<<sum<<endl;    
}


