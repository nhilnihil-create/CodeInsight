#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e11;
using Graph = vector<vector<int>>;

signed main(){
  int N;
  cin >> N;

  int ans = 0;
  for( int A = 1; A < N; A++ ){
    ans += (N-1)/A;
  }
  cout << ans << endl;
}
