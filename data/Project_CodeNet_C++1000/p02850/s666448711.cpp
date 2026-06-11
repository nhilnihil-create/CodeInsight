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

void dfs(ll a, ll c, const vvll &e, vb &ald, map<P, ll> &col){
    ald[a] = true;
    ll n = 1;
    for(auto x: e[a]){
        if(!ald[x]){
            if(n == c){n++;}
            P g = mp(a, x), h = mp(x, a);
            if(col.find(g) == col.end()){
                col[g] = n;
            }
            if(col.find(h) == col.end()){
                col[h] = n;
            }
            dfs(x, n, e, ald, col);
            n++;
        }
    }
}

int main(){
    ll N; cin >> N;
    vvll e(N+1, vll(0));
    vvll m(N-1, vll(2));
    rep(i,0, N-1){
        ll a, b; cin >> a >> b;
        m[i][0] = a; m[i][1] = b;
        e[a].emplace_back(b);
        e[b].emplace_back(a);
    }
    ll ma = 0;
    rep(i, 1, N+1){
        ma = max(ma, sz(e[i]));
    }
    vb ald(N+1, false);
    map<P, ll> col;
    dfs(1, 0, e, ald, col);
    prtl(ma);
    rep(i, 0, N-1){
        P b = mp(m[i][0], m[i][1]);
        prtl(col[b]);
    }
}