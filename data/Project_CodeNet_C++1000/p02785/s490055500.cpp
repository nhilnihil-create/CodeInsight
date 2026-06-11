#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,k,cost=0;
    cin>>n>>k;
    vector<ll> h(n);
    rep(i,n){
        cin>>h[i];
    }
    sort(h.begin(),h.end());
  reverse(h.begin(),h.end());
    rep(i,n){
        if(i>=k){
            cost+=h[i];
        }
    }
    cout<<cost;
}