// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n, k; cin >> n >> k;
  vector<int> C(n, 0);
  loop(i,0,k) {
    int d, a;
    cin >> d;
    loop(j,0,d) {
      cin >> a;
      a--;
      C[a]++;
    }
  }
  
  int cnt = 0;
  loop(i,0,n) cnt += C[i]==0;
  cout << cnt << endl;
  return 0;
}
