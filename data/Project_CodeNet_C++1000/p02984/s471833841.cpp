#include <bits/stdc++.h>
using namespace std;

#define Task "abc"
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int n;
int a[maxn];
ll ans[maxn];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i] = a[i] * 2;
  ll sum = 0;
  for (int i = 1; i <= n; ++i) sum = sum + a[i];
  sum /= 2;
  ll t = 0;
  for (int i = 2; i <= n; i += 2) t += a[i];
  ans[1] = sum - t;
  for (int i = 2; i <= n; ++i) ans[i] = a[i-1] - ans[i-1];
  for (int i = 1; i <= n; ++i) cout << ans[i] <<' ';

}

