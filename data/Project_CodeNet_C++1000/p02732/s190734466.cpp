// g++ .cpp && ./a.out
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef pair<int, int> p;
typedef long long ll;

const int mod = 1000000007;
const int inf = 1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> cnt(n + 1);
  rep(i, n) cnt[a[i]]++;
  ll sum = 0;
  rep(i, n + 1) sum += (cnt[i] * (cnt[i] - 1) / 2);
  rep(i, n) cout << sum - (cnt[a[i]] - 1) << endl;
}
