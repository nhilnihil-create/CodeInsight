//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

const int N = 2e5+10;

//head

int n;
ll k;
int a[N], f[N];

bool able(ll u) {
  ll cn = 0;
  rep(i, n) {
    ll p = u/f[i];
    cn += max(0LL, a[i]-p);
  }
  return cn <= k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n) {
    cin >> f[i];
  }

  sort(a, a+n);
  sort(f, f+n, greater<int>());

  ll lb = -1, mid, ub = 1e13;
  while(ub-lb != 1) {
    mid = (lb+ub)>>1;
    if(able(mid)) ub = mid;
    else lb = mid;
  }

  cout << ub << endl;
}