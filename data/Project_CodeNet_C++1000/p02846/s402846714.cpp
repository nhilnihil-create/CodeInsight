#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll T1;
    cin >> T1;
    ll T2;
    cin >> T2;
    ll A1;
    cin >> A1;
    ll A2;
    cin >> A2;
    ll B1;
    cin >> B1;
    ll B2;
    cin >> B2;
    ll S=T1*(A1-B1);
    ll T=T2*(A2-B2);
    if(S+T==0){
        prt("infinity")return 0;
    }
    if(S<0){
        S*=-1;T*=-1;
    }
    if(S+T>0){
        prt(0)return 0;
    }
    ll k=-T-S;
    if(S%k!=0){
        prt(2*(S/k)+1)return 0;
    }
    else prt(2*(S/k))

    return 0;
}
