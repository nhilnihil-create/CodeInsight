#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
ll n, q;
vector<vector<ll>> to(n);
vector<bool> seen(n);
vector<ll> score(n);
vector<ll> ans(n);

void dfs(ll node, ll num){
    seen[node] = true;
    ans[node] = num;

    for(ll next : to[node]){
        if(seen[next]){
            continue;
        }else{
            dfs(next, num + score[next]);
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> n >> q;
    to.resize(n);
    rep(i, n-1){
        ll a, b; cin >> a >> b; a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    score.resize(n);
    rep(i, q){
        ll p, x; cin >> p >> x; p--;
        score[p] += x;
    }

    seen.resize(n);
    ans.resize(n);
    dfs(0, score[0]);

    rep(i, ans.size()){
        cout << ans[i] << " ";
    }
    br;


}