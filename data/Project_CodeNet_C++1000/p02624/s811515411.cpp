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
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    ll n;cin >>n;
    Vl cnt(n+1,0);
    for (int i =1; i <=n; ++i) {
        for (int j =i; j <=n;j+=i) {
            cnt[j]++;
        }
    }
    ll ans=0;
    for (int i =1; i <=n; ++i) {
        ans+=i*cnt[i];
    }
    cout <<ans <<endl;
}

