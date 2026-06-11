#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

typedef long double ld;
typedef long long ll;
const ll MOD = (ll)1e9 + 7;

void print()
{
  std::cout << std::endl;
}

template<class T>
void print(T param)
{
  std::cout << param << std::endl;
  return;
}

template<class T, class... S>
void print(T param1, S... param2)
{
  std::cout << param1 << " "; print(std::forward<S>(param2)...);
}

void fail()
{
  return;
}

void solve()
{
  ll N, K;
  std::cin >> N >> K;

  ll ans = 0LL;

  // 0からNまで並んでいるとする
  // i 個選ぶ
  for (ll i = K; i <= N + 1; i++) {
    ll min_val = (0 + (i-1))   * i / 2;  // 0 〜 i-1
    ll max_val = (N + (N-i+1)) * i / 2;  // N-i+1 〜 N
    ans = (ans + (max_val - min_val + 1)) % MOD;
  }

  print(ans);
  return;
}

int main()
{
  solve();
  return 0;
}
