#include <bits/stdc++.h>
using namespace std;

// repetition
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

// const value
// const ll MOD = 1e9 + 7;
// const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
// const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

// conversion
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline ll toLL(string s) {
  ll v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}

void solve(VLL &p, VLL &m) {
  FOR(i, 1, p.size()) {
    cout << m.back() << " " << p[i] << endl;
    m.back() -= p[i];
  }

  rep(i, m.size()) {
    cout << p[0] << " " << m[i] << endl;
    p[0] -= m[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VLL a(n);
  rep(i, n) cin >> a[i];
  VLL m, p;
  ll sum = 0;

  if(n == 2) {
    sort(all(a));
    cout << a[1] - a[0] << endl;
    cout << a[1] << " " << a[0] << endl;
    return 0;
  }

  rep(i, n) {
    if(a[i] >= 0)
      p.push_back(a[i]);
    else
      m.push_back(a[i]);

    sum += abs(a[i]);
  }

  if(p.size() > 0 && m.size() > 0) {
    cout << sum << endl;
    solve(p, m);
    return 0;
  }

  if(p.size() > 0) {
    sort(all(p));
    cout << sum - 2 * p[0] << endl;
    m.push_back(p[0] - p[1]);
    cout << p[0] << " " << p[1] << endl;
    VLL pp;
    FOR(i, 2, p.size()) pp.push_back(p[i]);
    solve(pp, m);
  } else {
    sort(all(m));
    cout << sum + 2 * m.back() << endl;
    ll mSize = m.size();
    p.push_back(m[mSize - 1] - m[mSize - 2]);
    cout << m[mSize - 1] << " " << m[mSize - 2] << endl;
    VLL mm;
    rep(i, mSize - 2) mm.push_back(m[i]);
    solve(p, mm);
  }

  return 0;
}
