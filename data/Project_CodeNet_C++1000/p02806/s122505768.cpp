#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;

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

int main()
{
  ll N;
  std::cin >> N;
  std::vector< std::pair<std::string, ll> > vp(N);
  for (ll i = 0; i < N; i++) {
    std::cin >> vp[i].first >> vp[i].second;
  }
  std::string X;
  std::cin >> X;

  bool is_on = false;
  ll ans = 0LL;
  for (ll i = 0; i < N; i++) {
    if (is_on) {
      ans += vp[i].second;
    }

    if (X == vp[i].first) {
      is_on = true;
    }
  }

  print(ans);
  return 0;
}
