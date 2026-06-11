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
const ll MOD=1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;

inline ld dist(ld x1,ld y1,ld x2,ld y2){
    return (ld)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> X(N,0);
    vector<ll> Y(N,0);
    for(ll i=0;i<N;++i)cin>>X[i]>>Y[i];
    vector<P> vec(N);
    for(ll i=0;i<N;++i)vec[i]=P(X[i],Y[i]);
    sort(vec.begin(), vec.end(),[&](P l,P r){return atan2(l.second,l.first)<atan2(r.second,r.first);});
    for(ll i=0;i<N;++i)vec.emplace_back(vec[i]);
    ld ans=0.0;
    for(ll i=0;i<N;++i){
        for(ll j=0;j<N;++j){
            ld x=0,y=0;
            for(ll k=i;k<=i+j;++k){
                x+=vec[k].first;
                y+=vec[k].second;
            }
            chmax(ans,dist(0.0,0.0,x,y));
        }
    }
    cout << fixed << setprecision(20);
    prt(ans);fl
    return 0;
}

