#include <iostream>
#include <bitset>
#include <algorithm>

typedef long long ll;
const ll MAXN = 1e6+5;

std::bitset<MAXN> is;
int pr[MAXN], primes = 0;
void sieve() {
  is[2] = true; pr[primes++] = 2;
  for (int i = 3; i < MAXN; i += 2) is[i] = 1;
  for (ll i = 3; i*i < MAXN; i += 2)
    if (is[i])
      for (ll j = i*i; j < MAXN; j += i)
        is[j]= 0;
  for (int i = 3; i < MAXN; i += 2)
    if (is[i])
      pr[primes++] = i;
}


ll N;

int main() {
  sieve();

  std::cin >> N;
  ll ans = 0;

  for (int i = 0; i < primes; ++i) {
    if (pr[i] > N)      break;
    int cnt = 0;
    while (N % pr[i] == 0) {
      cnt++;
      N /= pr[i];
    }
    for (int j = 1; j <= cnt; j++) {
      ans++;
      cnt -= j;
    }
  }
  if (N != 1)
    ans++;

  std::cout << ans << "\n";


  return 0;
}
