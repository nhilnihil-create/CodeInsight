#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    //int t; cin>>t; while(t--){
    ll n,p=0; cin>>n;
    for(int j=2;j<=sqrt(n);j++){
        if(n%j==0){p=1; break;}
    }
    if(p==0){
        cout<<n-1;
    }
    else{
        for(int j=2;j<=sqrt(n);j++){
            if(n%j==0){p=j;}
        }
        ll k=n/p;
        cout<<k-1+p-1;
    }
}

