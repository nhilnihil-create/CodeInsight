#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> list(n);
  int total=0;
  for(int i=0; i<n; i++) {
    cin >> list.at(i);
    total += list.at(i);
  }
  int x=0,y=0,ans=100000000;
  for(int i=0; i<n-1; i++) {
    x += list.at(i);
    y = abs((total-x)-x);
    ans = min(ans,y);
  }
  cout << ans << endl;
}