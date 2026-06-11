#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main() {
    ll ans=0;
    ll n,a,b;cin >>n>>a>>b;
    ans=(n/(a+b))*a;
    n%=(a+b);
    ans+=min(a,n);
    cout <<ans <<endl;
}
