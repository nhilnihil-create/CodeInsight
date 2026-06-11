#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> list(n);
  for(int i=0; i<n; i++) {
    cin >> list.at(i);
  }
  int ans = 0;
  for(int i=1; i<n-1; i++) {
    if(list.at(i) != min({list.at(i-1),list.at(i),list.at(i+1)})) {
      if(list.at(i) != max({list.at(i-1),list.at(i),list.at(i+1)})) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}