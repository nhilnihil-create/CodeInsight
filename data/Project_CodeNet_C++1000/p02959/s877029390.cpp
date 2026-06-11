#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> A(n+1), B(n);
  for (int i = 0; i < n + 1; ++i) cin >> A[i];
  for(int i = 0; i < n; ++i) cin >> B[i];
  long long int count=0;
  for (int i = 0; i < n; ++i) {
      count += min(A[i], B[i]);
      B[i] -= min(A[i], B[i]);
      count += min(A[i+1], B[i]);
      A[i + 1] -= min(A[i + 1], B[i]);
  }
  cout << count << endl;
  return 0;
}