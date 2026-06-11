#include <iostream>
#include <algorithm>
#define rep(i, n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[200000];
  rep(i, N) cin >> A[i];
  
  sort(A, A + N, greater<int>());
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    ans += A[i/2];
  }
  cout << ans;
}