#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;

int main() {

  int K, N;
  cin >> K >> N;

  vector<int> ans(2*K-1);

  // backward
  rep(i, K-1) {
	ans[i] = N-K+1 +i;
  }


  // center
  ans[K-1] = N;


  // forward
  int cnt = 1;
  for(int i=K; i<2*K-1; ++i) {
	ans[i] = N+cnt;
	cnt++;
  }


  rep(i,2*K-1) cout << ans[i] << endl;
  return 0;
}