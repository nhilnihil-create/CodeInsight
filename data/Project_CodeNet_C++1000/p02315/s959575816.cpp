#include <iostream>
#include <vector>

using namespace std;
// template for creating 2d vector
template<typename T>
vector<vector<T>> make_2d_vector(size_t rows, size_t cols, T init)
{ return vector< vector<T> >(rows, vector<T>(cols, init)); }



#define debug(x) cout << #x << "==" << x << endl;

const int inf = 100000000;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);

  int N, W;
  cin >> N >> W;

  vector<int> v(N), w(N);
  for(int i = 0; i < N; i++) { cin >> v[i] >> w[i]; }

  // dp[i][j] := i???????????§?????????????????£??????j????¶?????????????????????????????????§
  auto dp = make_2d_vector(N+1, W+1, 0);

  for(int i = 0; i <= N; i++ ) {
    for(int j = 0; j <= W; j++) {

      if( i == 0 || j == 0 ) { dp[i][j] = 0; }

      else {
        if( w[i-1] <= j ) {
          dp[i][j] = max(dp[i-1][j-w[i-1]] + v[i-1], dp[i-1][j]);
        } else {
          dp[i][j] = dp[i-1][j];
        }
      }

    }
  }

  cout << dp[N][W] << "\n";

  return 0;
}