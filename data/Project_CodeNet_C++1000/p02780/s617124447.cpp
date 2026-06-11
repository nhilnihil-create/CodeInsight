#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll,ll>;
using um = unordered_map<ll,ll>;
#define fl cout<<flush;
#define endl '\n'
template <typename T> inline void prt(T v){cout<<v<<'\n';}
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=(ll)1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ld N,K;
    cin>>N>>K;
    vector<ld> p(N,0);
    for(ll i=0;i<N;++i)cin>>p[i];
    ll sum=-INF;
    ll t=0;
    for(ll i=0;i<K;++i)t+=p[i];
    sum=t;
    for(ll i=0;i<N-K;++i){
        t+=p[K+i];
        t-=p[i];
        chmax(sum,t);
    }
    cout << fixed << setprecision(12);
    cout<<((ld)(sum+K))/2.0<<endl;

    return 0;
}

