#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll gcd(ll x,ll y){ return y ? gcd(y,x%y) : x;}

ll func(ll x){
    vector<ll> v;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            v.push_back(i);
            x/=i;
        }
        while(x%i==0){
            x/=i;
        }
    }
    if(x!=1) v.push_back(x);
    return (ll)v.size();
}

int main(){
    ll a,b;
    cin>>a>>b;
    ll x=gcd(a,b);
    cout<<func(x)+1<<endl;
}