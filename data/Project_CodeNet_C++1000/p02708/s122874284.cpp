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
    ll ans=0;
    ll n,k;cin>>n>>k;
    for (int i = k; i <=n+1; ++i) {
        ans+=(n-i+1)*i+1;
        ans%=mod;
    }
    cout <<ans <<endl;
    return 0;
}