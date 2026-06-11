#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = unsigned long long;
using namespace std;
 
int main(){
    ll x;cin>>x;
    ll a=100;
    ll i=0;
    while(a<x){
        a+=a/100;
        i++;
    }
    cout<<i<<endl;
}