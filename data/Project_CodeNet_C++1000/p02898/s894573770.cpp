#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, K, ans;
  cin >> N >> K;
  ans=0;
  vector<int> h(N);
  for (int i=0; i<N; i++) {
    cin >> h.at(i);
  }
  for (int j=0; j<N; j++) {
    if (h.at(j)>=K) {
      ans=ans+1;
    }
  }
  cout << ans << endl;
}
