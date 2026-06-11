#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define pii pair<int, int>
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define Debug(X) cout << #X << " = " << X << '\n'
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

ll n, len, w;
pair<ll,ll> a[maxn];
ll ans = 0;
ll p[maxn];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);  freopen(Task".out", "w", stdout);
  cin >> n >> len >> w;
  #define X first
  #define H second
  for (int i = 1; i <= n; ++i) cin >> a[i].X >> a[i].H;
  sort(a + 1, a + n + 1);
  len *= 2;

  for (int i = 1; i <= n; ++i){
    p[i] = p[i] + p[i-1];
    ll del = p[i] * w;
    if (del >= a[i].H) continue;
    a[i].H -= del;
    int nextpos = upper_bound(a+1, a+n+1, mp(a[i].X + len, ll(1e18)) ) - a;
    nextpos--;
    ll num = (a[i].H - 1) / w + 1;
    ans = ans + num;
    p[i] = p[i] + num; p[nextpos+1] -= num;
  }
  cout << ans;
}


