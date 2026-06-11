#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> B(N+1, 0);
  int p;
  for (int i=1; i<N+1; i++) {
    cin >> p;
    B[i]=B[i-1]+p;
  }
  
  int C=0;
  for (int i=0; i<N+1; i++) {
    if (B[i]>X) {break;}
    C++;
  }
  cout << C << endl;
}
