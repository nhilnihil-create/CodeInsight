#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<math.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,n,a) for(int i = (int)(n); i >= (int)(a); i--)

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

int main(void)
{
    int n, q;
    cin >> n >> q;

    v2_int g(n);
    
    irep(i, n-1) {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    
    v_ll dist(n, 0);

    irep(i, q) {
        int p, x;
        cin >> p >> x;
        dist[p-1] += x;
    }

    queue<int> que;
    que.push(0);
    v_bool used(n,false);
    used[0] = true;
    
    while(que.size()) {
        int now = que.front(); que.pop();
        for(auto node : g[now]) {
            if(used[node]) { continue; }
            dist[node] += dist[now];
            used[node] = true;
            que.push(node);
        }
    }
    irep(i,n) {
        cout << dist[i] << endl;
    }
    return 0;
} /*atcoder*/

