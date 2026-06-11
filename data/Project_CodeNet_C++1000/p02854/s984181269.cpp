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
    ll n;cin >>n;
    vector<ll>a(n);
    vector<ll>sum(n+1,0);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        sum[i+1]=sum[i]+a[i];
    }
    ll d=INFll;
    for (int i = 1; i <n; ++i) {
        d=min(abs(2*sum[i]-sum[n]),d);
    }
    cout <<d<<endl;
    return 0;
}