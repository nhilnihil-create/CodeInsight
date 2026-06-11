#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> A(M);
  rep(i,N) cin >> A[i];
  for(int i=0; i<M; i++) {
    N -= A[i];
    if(N<0) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << N << endl;
}