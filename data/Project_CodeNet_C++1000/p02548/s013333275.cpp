#include <iostream>

typedef long long ll;

const ll MAXN = 1000005;
int cnt[MAXN];

int main() {
  for (int i = 0; i < MAXN; ++i)
    cnt[i] = 0;

  for (ll i = 1; i < MAXN; ++i)
    for (ll j = i*i; j < MAXN; j += i)
      cnt[j] += (i*i == j ? 1 : 2);

  int N;  std::cin >> N;
  ll ans = 0;
  for (int i = 1; i < N; ++i)
    ans += cnt[i];
  std::cout << ans << "\n";

  return 0;
}
