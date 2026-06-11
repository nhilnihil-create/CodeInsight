#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,k;cin >>n>>k;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    ll cnt=0;
    ll cnt2=0;
    for (int i = 0; i < n-1; ++i) {
        for (int j =i+1; j < n; ++j) {
            if(a[i]>a[j])cnt++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(a[i]>a[j]){
                cnt2++;
            }
        }
    }
    ll ans;
    ll now;
    ans=cnt*k%mod;
    now=k*(k-1)/2%mod;
    now*=cnt2;
    now%=mod;
    ans+=now;
    ans%=mod;
    cout <<ans <<endl;
}
