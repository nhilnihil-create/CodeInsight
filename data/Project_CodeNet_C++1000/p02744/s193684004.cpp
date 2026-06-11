#pragma GCC optimize ("O3")
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
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
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
ll INF = 1LL<<60;
ll M = 1000000007;
vector<string> v(0);

void dfs(ll a, ll n, string p, vector<string> &v){
    if(a == n){
        v.emplace_back(p);
        return;
    }
    char mx = a - 1;
    rep(i, 0, a){
        string m = p;
        m.push_back(p[i]);
        dfs(a+1, n, m, v);
        mx = max(mx, p[i]);
    }
    string z = p;
    z.push_back(mx + 1);
    dfs(a+1, n, z, v);
}

int main(){
    ll N; cin >> N;
    vector<string> v(0);
    string p = "a";
    dfs(1, N, p, v);
    set<string> h;
    for(auto x : v){
        h.insert(x);
    }
    for(auto x: h){
        prtl(x);
    }
}