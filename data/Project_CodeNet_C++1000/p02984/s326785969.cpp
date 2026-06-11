#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  
  ll N;
  cin >> N;
  
  vector<ll> A(2 * N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[N+i] = A[i];
  }
  
  ll odd= 0, even = 0;
  for (int i = 0; i < N/2; i++) {
    odd += A[2 * i + 1];
    even += A[2 * i];    
  }
  
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
  }
  sum /= 2;
  
  cout << 2 * (sum - odd) << " "; // x1のみ
  
  for (int i = 2; i <= N; i++) {
    if (i % 2) {
      odd -= A[i-2];
      odd += A[i+(N/2 - 1)* 2];
      cout << 2 * (sum - odd) << " ";
    } else {
      even -= A[i-2];
      even += A[i+(N/2 - 1) * 2];
      cout << 2 * (sum - even) << " ";
    }
    
  }
  
}