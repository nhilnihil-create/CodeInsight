#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int minN = 200000;
  vector<int> P(N); vector<int> minV(200000);
  for (int i =0; i<N; i++) {
    cin >> P.at(i);
    minN = min(P.at(i),minN);
    minV.at(i) = minN;
  }
  
  int ans =0;
  for (int i =0; i<N; i++) {
    if (P.at(i) == minV.at(i)) ans++;
  }
  cout << ans << endl;
}