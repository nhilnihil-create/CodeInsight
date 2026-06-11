#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> vec(n, 0);
  reps(i, 1, n+1) {
    reps(j, i+1, n+1) {

      int a = abs(j - i);
      int b = abs(j-y) + 1 + abs(x-i);
      vec.at(min(a, b))++;
      
    }
  }
  reps(i, 1, n) {
    cout << vec.at(i) << endl;
  }
  return 0;
}