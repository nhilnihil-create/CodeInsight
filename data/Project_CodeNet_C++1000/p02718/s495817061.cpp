#include <bits/stdc++.h>

using namespace std;

int main(void){

  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i=0; i<n; i++) {
    cin >> A[i];
  }

  int total = 0;
  for (int i=0; i<n; i++) {
    total += A[i];
  }

  int canSelect = 0;
  for (int i=0; i<n; i++) {
    if (A[i]*4*m >= total) {
      canSelect++;
     }
  }

  if (canSelect >= m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0; 
}
