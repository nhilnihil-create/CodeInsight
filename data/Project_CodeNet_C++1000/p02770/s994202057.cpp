//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0xccccccc;
const ll LINF = 922337203685477580LL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

#define N 5010

//head

int k, q;
int d[N];
int nd[N];
ll sum, cnt0;
int n, x, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> q;
  rep(i, k) cin >> d[i];
  while(q--) {
    cin >> n >> x >> m;
    x %= m;
    rep(i, k) nd[i] = d[i]%m;
    cnt0 = 0;
    rep(i, k) if(!nd[i]) cnt0++;
    sum = accumulate(nd, nd+k, 0LL);
    int u = (n-1)/k;
    sum *= u;
    cnt0 *= u;
    sum += x;
    rep(i, n-1-u*k) sum += nd[i];
    rep(i, n-1-u*k) if(!nd[i]) cnt0++;
    cout << n-1-sum/m-cnt0 << '\n';
  }
}