#include <bits/stdc++.h>
using namespace std; inline void fileio(const char* in, const char* out) { freopen(in, "r", stdin); freopen(out, "w", stdout); } 
#define TD typedef
#define forx(i,n) for(int i = 0; i < (n); ++i)
TD long long ll; TD long double ld; TD pair<int,int> pii; TD pair<ll,ll> pll; TD vector<int> VI; TD vector<bool> VB; TD vector<ll> VL;
const char nl = '\n'; const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3fll; const ld EPS = 1e-9, PI = acos(-1);
#define ff first
#define ss second

int main() {
  atexit([](){ cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // Emily <3
  int n;
  cin >> n;
  if (__builtin_popcount(n) == 1) {
    cout << "No" << nl;
    return 0;
  }
  cout << "Yes" << nl;
  bool even = (n % 2 == 0);
  int rt = n+1;
  for (int i = 1; i <= 2; i++) {
    cout << i << " " << i+1 << nl;
  }
  cout << "3 " << n+1 << nl;
  for (int i = n+1; i <= n+2; i++) {
    cout << i << " " << i+1 << nl;
  }
  for (int nx = 5; nx <= n; nx+=2) {
    cout << rt << " " << nx << nl;
    cout << nx << " " << nx-1 << nl;
    cout << rt << " " << nx+n-1 << nl;
    cout << nx+n-1 << " " << nx+n << nl;
  }
  if (even) {
    cout << n << " " << n-1 << nl;
    int search = n^1^(n-1);
    cout << search+n << " " << n+n << nl;
  }
  
  return 0;
}

