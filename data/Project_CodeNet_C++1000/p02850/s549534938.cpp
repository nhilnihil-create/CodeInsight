#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

vector<vector<LP>> to;
vl color;

void dfs(int v, int p, int pc) {
    if (p != -1 && to[v].size() == 1) return;

    int c = 1;
    for (auto nv : to[v]) {
        if (p == nv.fi) continue;
        if (c == pc) c++;
        color[nv.se] = c;
        dfs(nv.fi, v, c);
        c++;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    to = vector<vector<LP>>(n);
    rep(i, n - 1) {
        ll v1, v2;
        cin>>v1>>v2; v1--; v2--;

        to[v1].emplace_back(v2, i);
        to[v2].emplace_back(v1, i);
    }
    int ans = 0;
    rep(i, n) {
        chmax(ans, sz(to[i]));
    }
    cout<<ans<<endl;
    color = vl(n - 1);
    dfs(0, -1, -1);
    rep(i, n - 1) cout<<color[i]<<endl;
}