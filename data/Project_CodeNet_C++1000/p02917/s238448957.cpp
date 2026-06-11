#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N - 1);
  for(int i = 0; i < N - 1; i++) {
    cin >> B[i];
  }
  ll sum = 0;
  for(int i = 0; i < N; i++) {
    if(i == 0) {
      A[i] = B[i];
    }
    else if(i == N - 1) {
      A[i] = B[i - 1];
    }
    else {
      A[i] = min(B[i - 1], B[i]);
    }
    sum += A[i];
  }
  cout << sum << endl;
}