#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=100000007;
const ll INF=1000000101001;
vector<ll> enum_div(ll n){
    vector<ll> res;
for(ll i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            res.push_back(i);
            if(i*i != n){
                res.push_back(n/i);
            }
        }
    }
    sort(res.begin(),res.end(),greater<int>());
    return res;
}
int main(){
    ll n,k;cin >> n >> k;
    ll a[n];
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll M=sum;
    const auto &res=enum_div(M);
    ll ans=0;
    for(int i=0;i<res.size();i++){
        ll cnt=0;
        ll r[n];
        rep(j,n){
           r[j]=a[j]%res[i];
        }
        sort(r,r+n);
        ll rsum=0;
        ll lsum=0;
        rep(j,n){
            rsum+=res[i]-r[j];
        }
        rep(j,n){
            lsum+=r[j];
            rsum-=res[i]-r[j];
            if(max(lsum,rsum)<=k){
                cout << res[i] << endl;
                return 0;
            }
        }
    }
}