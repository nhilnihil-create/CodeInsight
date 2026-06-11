#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;

vvll dp(1000, vll(1000, -1));

ll dfs(ll h, ll w, ll a, ll b, const vvc &m){
    if(dp[a][b] > -1){return dp[a][b];}
    if(a == h-1&&b == w-1){return dp[a][b] = 0;}
    ll p = 1000;
    if(a+1<h){
        ll x = dfs(h, w, a+1, b, m);
        if(m[a][b] != m[a+1][b]){x++;}
        p = min(p, x);
    }
    if(b+1<w){
        ll y = dfs(h, w, a, b+1, m);
        if(m[a][b] != m[a][b+1]){y++;}
        p = min(p, y);
    }
    return dp[a][b] = p;
}

int main(){
    ll H, W; cin >> H >> W;
    vvc map(H, vc(W));
    rep(i,0,H){
        rep(j,0,W){
            cin >> map[i][j];
        }
    }
    ll k = dfs(H, W, 0, 0, map);
    if(map[0][0] == '#'){
        prtl(k/2 + 1);
    }else{
        prtl((k+1)/2);
    }
}