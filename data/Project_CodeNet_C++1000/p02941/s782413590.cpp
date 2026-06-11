#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 998244353;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 2e5 + 5;

int a[MAXN], f[MAXN];

int n;
int M(int i) {
  return (i + n) % n;
}

bool check(int i) {
  return a[i] > a[M(i + 1)] && a[i] > a[M(i - 1)];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  REP(i, n) cin >> f[i];
  REP(i, n) cin >> a[i];

  vector<int> good;
  REP(i, n) {
    if(check(i)) {
      good.pb(i);
    }
  }

  ll sol = 0;

  while(good.size()) {
    int i = good.back();
    good.pop_back();

    int sums = a[M(i + 1)] + a[M(i - 1)];
    int times = max(0, (a[i] - max(f[i], max(a[M(i + 1)], a[M(i - 1)])) - 1)) / sums;

    if(a[i] == f[i]) times --;

    times ++;
    sol += times;

    a[i] -= times * sums;
    if(check(M(i + 1))) good.pb(M(i + 1));
    if(check(M(i - 1))) good.pb(M(i - 1));
  }

  REP(i, n) if(a[i] != f[i]) {
    cout << -1 << endl;
    return 0;
  }

  cout << sol << endl;
}
