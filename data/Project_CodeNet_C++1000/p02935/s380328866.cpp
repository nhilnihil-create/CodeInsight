#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<float> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  
  sort(A.begin(), A.end() );
 
  for (int i = 0; i < n - 1; i++) {
  	A[i + 1] = (A[i] + A[i + 1]) / 2;
  }
  cout << A[A.size() - 1] << endl;
}
