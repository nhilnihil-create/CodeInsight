#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  int K = min(A,B);
  int L = max(A,B);
  for (int i = 0; i < L; i++)
    cout << K;
  cout << endl;
  
     
}
