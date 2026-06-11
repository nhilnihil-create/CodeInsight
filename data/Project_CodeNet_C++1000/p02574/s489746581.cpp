#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;

#define MAX 1000010

const int MOD = 1e9 + 7;

using ll = long long;

bitset<MAX> prime, used;

vi fact;

void sieve(int n) {
  prime.set();
  int i;
  for (i = 2; i * i <= n; i++) {
    if (prime[i]) {
      fact[i] = i;
      for (int j = i * i; j <= n; j += i) {
        prime[j] = 0;
        if (fact[j] == -1)
          fact[j] = i;
      }
    }
  }

  for (; i <= n; i++)
    if (prime[i])
      fact[i] = i;
}

int main() {
  int n;
  scanf("%d", &n);
  vi v(n);

  int mx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    mx = max(mx, v[i]);
  }

  fact.resize(mx + 1, -1);
  sieve(mx + 1);


  bool pairwise = true;
  int gcd;
  for (int i = 0; i < n; i++) {
    if (i == 0) gcd = v[i];
    else if (gcd > 1)
      gcd = __gcd(gcd, v[i]);

    if (pairwise) {
      while (v[i] > 1) {
        int &p = fact[v[i]];

        if (used[p]) {
          pairwise = false;
          break;
        }

        used[p] = true;
        while (v[i] % p == 0) v[i] /= p;
      }
    } else if (gcd == 1) break;
  }

  if (pairwise)
    printf("pairwise coprime\n");
  else if (gcd == 1)
    printf("setwise coprime\n");
  else
    printf("not coprime\n");

  return 0;
}
