#include <bits/stdc++.h>

using namespace std;
 
#define debug(s) cerr << #s << " = " << s << '\n'
#define all(v) (v).begin(), (v).end()
#define mem(a,val) memset(a, val, sizeof a)
 
#define ff first
#define ss second
typedef long long ll;

const int N = 200010;
int n;
ll arr[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  sort(arr + 1, arr + 1 + n, greater<ll>());
  ll ans = arr[1];
  n -= 2;
  int cur = 2;
  while (n) {
    if (n == 1) {
      ans += arr[cur];
      n--;
    }
    else {
      ans += 2LL*arr[cur++];
      n -= 2;
    }
  }
  cout << ans << '\n';
}