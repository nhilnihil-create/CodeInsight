// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n, d; cin >> n >> d;
  vector<vector<int> > X(n);
  loop(i,0,n) {
    loop(j,0,d) {
      int x; cin >> x;
      X[i].push_back(x);
    }
  }
  
  int total = 0;
  loop(i,0,n-1) {
    loop(j,i+1,n) {
      int dist = 0;
      loop(k,0,d) {
        dist += (X[j][k]-X[i][k])*(X[j][k]-X[i][k]);
      }
      bool ok = false;
      loop(x,0,401) {
        ok |= x*x == dist;
      }
      total += ok;
    }
  }
  cout << total << endl;
  return 0;
}
