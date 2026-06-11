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

vvl to;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin>>n>>m;
    to = vvl(n);
    rep(i, m) {
        ll v1, v2;
        cin>>v1>>v2; v1--; v2--;
        to[v1].push_back(v2);
    }
    ll s, t;
    cin>>s>>t; s--; t--;

    vvl dist(n, vl(3));
    queue<LP> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        LP p = q.front(); q.pop();
        ll v = p.fi;
        ll d = p.se;
        if (dist[v][d % 3]) continue;
        dist[v][d % 3] = d;

        for (auto nv : to[v]) {
            q.emplace(nv, d + 1);
        }
    }

    if (dist[t][0]) cout<<dist[t][0] / 3<<endl;
    else cout<<-1<<endl;
}