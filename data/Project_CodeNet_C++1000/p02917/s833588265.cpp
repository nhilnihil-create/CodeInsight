#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> B(N);
  vector<int> A(N);
  for(int i = 0; i < N - 1; i++) {
    cin >> B[i];
  }

  A[0] = B[0];
  for(int i = 1; i <= N - 2; i++) {
    A[i] = min(B[i], B[i - 1]);
  }
  A[N - 1] = B[N - 2];

  int ans = 0;
  for(int i = 0; i < N; i++) {
    ans += A[i];
  }

  cout << ans << endl;
  return 0;
}
