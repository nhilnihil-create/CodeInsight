#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;

int main() {

  int N, K, Q;
  cin >> N >> K >> Q;

  int s = K-Q;

  vector<int> S(N, s);  // 先に持ち点からラウンド数減点した値で score を初期化

  vector<int> A(Q);  // who answerd
  rep(i, Q) cin >> A[i];

  // increase score who answered
  rep(i, Q) {
	S[A[i]-1]++;
  }

  rep(i, N) {
	if (S[i] > 0) cout << "Yes" << endl;
	else cout << "No" << endl;
  }

  return 0;
}
