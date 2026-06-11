#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)
#define fi first
#define se second

using ll = long long;
using v_int = std::vector<int>;
using v2_int = std::vector<v_int>;
using v_ll = std::vector<ll>;
using v2_ll = std::vector<v_ll>;
using v_string = std::vector<std::string>;
using v_bool = std::vector<bool>;
using v2_bool = std::vector<v_bool>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const double PI = 3.1415926535897932;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll MOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p)
{
    return o << "{" << p.first << "," << p.second << "}";
}

template<typename T, typename U, typename V> inline
ostream& operator<<(ostream &o, tuple<T,U,V> &p)
{
    return o << "{" << get<0>(p) << "," << get<1>(p) << "," << get<2>(p) << "}";
}

template<typename T> inline
istream& operator>>(istream &is, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) {
        is >> v[i]; 
    }
    return is;
}

template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) { 
        os << v[i];
        if(i != len-1) { os << ","; } 
    } 
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
    
    v_int a(n), b(n);

    irep(i, n-1) {
        cin >> a[i] >> b[i];
    }
    a[n-1] = 0; b[n-1] = 1;
    
    map<int, int> cost;
    irep(i, q) {
        int c, d;
        cin >> c >> d;
        cost[c] += d;
    }
    
    v2_int g(n+1);
    irep(i, n) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    
    queue<int> que;
    v_int dist(n+1, INF);
    que.push(0);
    dist[0] = 0;
    
    while(que.size()) {
        int node = que.front(); que.pop();
        
        irep(i, g[node].size()) {
            int next = g[node][i];
            if(dist[next] != INF) { continue; }
            que.push(next);
            dist[next] = dist[node] + cost[next];
        }
    }
    
    irep2(i, 1, n) {
        cout << dist[i] << endl;
    }
    return 0;
}


/*atcoder*/
