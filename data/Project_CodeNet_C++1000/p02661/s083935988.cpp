#include <bits/stdc++.h>

using namespace std;
 
#define debug(s) cerr << #s << " = " << s << '\n'
#define all(v) (v).begin(), (v).end()
#define mem(a,val) memset(a, val, sizeof a)
 
#define ff first
#define ss second
typedef long long ll;

const int N = 200010;
int n, a[N], b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  double ml, mr;
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  int ans;
  if (n & 1) {
    ml = a[n/2 + 1], mr = b[n/2 + 1];
    ans = max(0, (int)(mr - ml + 1));
  }
  else {
    ml = (a[n/2] + a[n/2 + 1]);
    mr = (b[n/2] + b[n/2 + 1]);
    ans = max(0, (int)(mr - ml + 1));
  }
  cout << ans << '\n';
}