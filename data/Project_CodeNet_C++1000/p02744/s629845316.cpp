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
const ll MOD=1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;

void dfs(char c,ll N,string S){
    if(N==0){cout<<S<<endl;return;}
    else for(char i='a';i<=c;i++){
        if(i==c)dfs(c+1,N-1,S+i);
        else dfs(c,N-1,S+i);
    }
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    dfs('a',N,"");fl

    return 0;
}
