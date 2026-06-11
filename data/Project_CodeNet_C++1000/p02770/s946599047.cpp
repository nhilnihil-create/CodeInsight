#include <bits/stdc++.h>
using namespace std; inline void fileio(const char* in, const char* out) { freopen(in, "r", stdin); freopen(out, "w", stdout); } 
#define TD typedef
#define forx(i,n) for(int i = 0; i < (n); ++i)
#define forxr(i,n) for(int i = (n)-1; i >= 0; --i)
TD long long ll; TD long double ld; TD pair<int,int> pii; TD pair<ll,ll> pll; TD vector<int> VI; TD vector<bool> VB; TD vector<ll> VL;
const char nl = '\n'; const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3fll; const ld EPS = 1e-9, PI = acos(-1);
#define ff first
#define ss second
#define all(c) c.begin(),c.end()

const int N = 5005;
int d[N];
int d2[N];
ll px[N];
int k;

void deal(int n, int x, int m) {
  n--;
  ll sum = 0;
  ll fulls = n/k;
  int extra = n - fulls*k;
  ll part = 0;
  for (int i = 0; i < k; ++i) {
    d2[i] = d[i] % m;
    if (d2[i] == 0) d2[i] = m;
    sum += d2[i];
    if (i < extra) {
      part += d2[i];
    }
  }
  ll tot = fulls * sum + part + x;
  ll ans = tot / m - x/m;
  cout << n-ans << nl;
}

int main() {
  atexit([](){ cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(12);
  // Emily <3
  int q;
  cin >> k >> q;
  for (int i = 0; i < k; ++i) {
    cin >> d[i];
    px[i+1] = px[i] + d[i];
  }
  while (q--) {
    int n,x,m;
    cin >> n >> x >> m;
    deal(n,x,m);
  }

  return 0;
}
