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
    vector<ll>p(n);
    for (int i = 0; i < n; ++i) {
        cin >>p[i];
        p[i]++;
    }
    ll ans=0;
    vector<ll>sum(n+1,0);
    for (int i = 0; i < n; ++i) {
        sum[i+1]=sum[i]+p[i];
    }
    for (int i = 0; i < n; ++i) {
        if(i+k>n)break;
        ans=max(ans,sum[i+k]-sum[i]);
    }
    string res=(ans%2)?".5":"";
    ans/=2;
    cout <<ans <<res<<endl;
    return 0;
}