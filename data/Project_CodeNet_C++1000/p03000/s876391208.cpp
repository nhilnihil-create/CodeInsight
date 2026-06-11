#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, X, ans;
  cin >> N >> X;
  ans=0;
  vector<int> D(N+1);
  D[0]=0;
  vector<int> L(N);
  for (int k=0; k<N; k++) {
    cin >> L[k];
  }
  for (int i=0; i<N; i++) {
    D[i+1]=D[i]+L[i];
  }
  for (int j=0; j<N+1; j++) {
    if (D[j]<=X) {
      ans=ans+1;
    }
  }
  cout << ans << endl;
}
