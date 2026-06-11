#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, ans;
  cin >> N;
  ans=0;
  vector<int> d(N);
  for (int i=0; i<N; i++) {
    cin >> d[i];
  }
  for (int j=0; j<N; j++) {
    for (int k=0; k<N; k++) {
      ans=ans+d[j]*d[k];
    }
  }
  for (int l=0; l<N; l++) {
    ans=ans-d[l]*d[l];
  }
  ans=ans/2;
  cout << ans << endl;
}