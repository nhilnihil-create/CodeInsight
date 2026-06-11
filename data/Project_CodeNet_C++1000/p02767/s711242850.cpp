#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> x(n);
  for(int &c : x) {
    cin >> c;
  }
  
  vector<int> ans(100, 0);
  for(int i = 1; i <= 100 ; i++) {
    for(int c : x) {
      ans.at(i -1) += (c - i) * (c - i);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.at(0) << endl;
}