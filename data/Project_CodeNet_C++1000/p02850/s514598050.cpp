#include <bits/stdc++.h>
//#include<iostream>
//#include<vector>
//#include<map>
//#include<math.h>
//#include<algorithm>

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define rrep2(i,n,a) for(int i = (int)(n); i >= (int)(a); i--)

#define fi first
#define se second

using namespace std;

using ll = long long;
using v_int = vector<int>;
using v2_int = vector<v_int>;
using v_ll = vector<ll>;
using v2_ll = vector<v_ll>;
using v_string = vector<string>;
using v_bool = vector<bool>;
using v2_bool = vector<v_bool>;
using pii = pair<int, int>;
using mii = map<int, int>;

const double PI = 3.1415926535897932;
const int INF = (int)2e9;
const ll LINF = (ll)2e18;
const ll MOD = 1000000007;
const int dc[8] = {1, -1, 0,  0, 1, -1,  1, -1};
const int dr[8] = {0,  0, 1, -1, 1,  1, -1, -1};

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p) {
    return o << "{" << p.first << "," << p.second << "}";
}
template<typename T> inline
istream& operator>>(istream &is, vector<T> &vec) {
    for(auto &v : vec) { is >> v; }
    return is;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &vec) {
    for(auto &v : vec) { os << v << ",";}
    return os;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<vector<T> > &mat) {
    for(auto &row : mat) { os << row << endl; }
    return os;
}

template<typename T> inline
void chmin(T &a, T b) { a = min(a, b); }
template<typename T> inline
void chmax(T &a, T b) { a = max(a, b); }

set<int> ans;

void solve(v2_int &g, map<pii,int> &tree, v_int &used, int from, int c = 0)
{
    int color = 1;
    for(auto to : g[from]) {
        if(to == from) { continue; }
        if(color == c) { color++; }
        if(used[to]) { continue; }
        used[to] = 1;
        if(to < from) { 
            tree[pii(to,from)] = color; 
        } else {
            tree[pii(from,to)] = color; 
        }

        ans.insert(color);
        solve(g, tree, used, to, color++);
    }
}

int main(void)
{
    int n;
    cin >> n;

    v2_int g(n);
    v_int a(n-1), b(n-1);
    rep(i,n-1) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    
    map<pii, int> tree;
    v_int used(n);
    used[0] = 1;

    solve(g, tree, used, 0);
    cout << ans.size() << endl;
    rep(i,n-1) {
        cout << tree[pii(a[i], b[i])] << endl;
    }
    return 0;
} /*atcoder*/

