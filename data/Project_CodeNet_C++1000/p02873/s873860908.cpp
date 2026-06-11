#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl '\n'
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
//const ll MOD=1e9+7;
const ll MOD=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N=S.size()+1;
    ll Min=0;
    vector<ll> A(N,0);
    vector<ll> L(N,0);
    vector<ll> R(N,0);
    for(ll i=0;i<N-1;++i){
        if(S[i]=='<'){
            L[i+1]=L[i]+1;
        }
        else L[i+1]=0;
    }
    for(ll i=N-2;i>=0;--i){
        if(S[i]=='>'){
            R[i]=R[i+1]+1;
        }
        else R[i]=0;
    }
    ll ans=0;
    for(ll i=0;i<N;++i)ans+=max(L[i],R[i]);
    prt(ans)fl

    return 0;
}
