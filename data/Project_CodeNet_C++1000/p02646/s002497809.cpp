#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main() {
  int A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  if( V <= W ) cout << "NO" << endl;
  else if( (V-W)*T >= abs(A-B) ) cout << "YES" << endl;
  else cout <<"NO" << endl;

}
