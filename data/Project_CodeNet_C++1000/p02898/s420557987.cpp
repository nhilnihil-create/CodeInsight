// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n, k; cin >> n >> k;
  vector<int> H(n);
  loop(i,0,n) cin >> H[i];
  int cnt = 0;
  for (auto&&h: H) {
    cnt += h >= k;
  }
  cout << cnt << endl;
  return 0;
}
