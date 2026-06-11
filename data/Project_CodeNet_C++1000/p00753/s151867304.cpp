#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
using namespace std;
#define MAX 300300
int primes[MAX];
signed main() {
  for (int i = 0; i < MAX; i++) primes[i] = -1;
  for (int i = 2; i < MAX; i++) {
    if (primes[i] == 0) continue;
    primes[i] = 1;
    for (int j = i*2; j < MAX; j+=i) {
      primes[j] = 0;
    }
  }

  int N;
  while (cin>>N, N!=0) {
    int ans = 0;
    for (int i = N+1; i <= 2*N; i++) {
      ans += primes[i];
    }
    cout << ans << endl;
  }
}

