#include <bits/stdc++.h>
using namespace std; inline void fileio(const char* in, const char* out) { freopen(in, "r", stdin); freopen(out, "w", stdout); } 
#define TD typedef
#define forx(i,n) for(int i = 0; i < (n); ++i)
TD long long ll; TD long double ld; TD pair<int,int> pii; TD pair<ll, ll> pll; TD vector<int> VI; TD vector<bool> VB; TD vector<ll> VL;
const char nl = '\n'; const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3fll; const ld EPS = 1e-9, PI = acos(-1);
#define ff first
#define ss second

int main() {
  atexit([](){ cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // Emily <3
  
  int n;
  cin >> n;
  VI balls(n);
  forx(i, n) {
    cin >> balls[i];
  }
  sort(balls.begin(), balls.end());

  vector<pii> ops;
  int x = balls[n-1];
  int y = balls[0];
  for (int i = 1; i < n-1; i++) {
    int b = balls[i];
    if (b < 0) {
      //sub from big
      ops.push_back({x, b});
      x -= b;
    } else {
      //sub from small
      ops.push_back({y, b});
      y -= b;
    }
  }
  cout << x-y << nl;
  for (auto a : ops) {
    cout << a.ff << " " << a.ss << nl;
  }
  cout << x << " " << y << nl;

  return 0;
}
