// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1172&lang=jp

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  const int M = 300000;
  bool prime[M];
  fill(prime, prime+M, true);
  prime[0] = prime[1] = false;
  for (int i=2; i<M; i++) {
    if (prime[i]) {
      int j = 2;
      while (i*j < M) {
	prime[i*j] = false;
	j++;
      }
    }
  }
  int n;
  while (scanf("%d", &n) != EOF && n) {
    int ans = 0;
    for (int i=n+1; i<=2*n; i++) {
      if (prime[i]) ans++;
    }
    printf("%d\n", ans);
  }
}