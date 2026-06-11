#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

typedef pair<int, int> Pi;
#define fi first
#define se second

signed main()
{
  bool prime[1000005];

  fill_n(prime, 1000005, true);

  for(int i = 2; i * i <= 1000005; i++) {
    if(prime[i]) {
      for(int j = i * i; j <= 1000005; j += i) prime[j] = false;
    }
  }

  int N;
  while(cin >> N, N) {
    int ans = 0;
    for(int i = N + 1; i <= 2 * N; i++) {
      ans += prime[i];
    }

    cout << ans << endl;
  }

  return 0;
}