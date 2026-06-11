#include <iostream>

using namespace std;

int main()
{
  int k, q; cin >> k >> q;
  int d[5000]; for (int i = 0; i < k; ++i) cin >> d[i];
  
  while (q--) {
    int n, x, m; cin >> n >> x >> m;
    int dm[5000]; for (int i = 0; i < k; ++i) dm[i] = d[i] % m;
    int quo = (n-1) / k, rem = (n-1) % k;
    int sum = 0;
    for (int i = 0; i < k; ++i) if (dm[i] == 0) {
      sum += quo; if(i < rem) ++sum;
    }
    long long last_a = x;
    for (int i = 0; i < k; ++i) {
      last_a += (long long)dm[i] * quo; if(i < rem) last_a += dm[i];
    }
    sum += last_a / m - x / m;
    cout << n - sum - 1 << endl;
  }
  
  return 0;
}