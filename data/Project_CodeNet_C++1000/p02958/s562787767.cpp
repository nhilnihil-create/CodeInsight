// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n; cin >> n;
  vector<int> P(n);
  loop(i,0,n) cin >> P[i];
  int count = 0;
  loop(i,1,n+1) {
    count += P[i-1]!=i;
  }
  if (count<=2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
