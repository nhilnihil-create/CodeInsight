#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i=0; i<N; i++) {
    cin >> p.at(i);
  }
  int ans=0;
  for (int j=0; j<N-2; j++) {
    if (p.at(j)<p.at(j+1) && p.at(j+1)<p.at(j+2)) {
      ans=ans+1;
    }
    if (p.at(j+2)<p.at(j+1) && p.at(j+1)<p.at(j)) {
      ans=ans+1;
    }
  }
  cout << ans << endl;
}
