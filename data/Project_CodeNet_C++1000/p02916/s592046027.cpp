#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;

int main() {

  int N;
  cin >> N;

  vector<int> A(N), B(N), C(N);

  rep(i, 2) {
	rep(j, N) {
	  if (i==0) cin >> A[j];
	  else if (i==1) cin >> B[j];
	}
  }

  rep(i, N-1) cin >> C[i];



  int ans = 0;
  rep(i, N) {
	ans+=B[A[i]-1];

	if (A[i]-1 == A[i-1]) {
	  ans+=C[A[i-1]-1];
	}
  }

  cout << ans << endl;

  return 0;
}