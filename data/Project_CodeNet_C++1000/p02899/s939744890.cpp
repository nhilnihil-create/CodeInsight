#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int a;
  vector<pair<int,int>> b(n);
  for(int i=0; i<n; i++) {
    cin >> a;
    b[i] = make_pair(a,i+1);
  }
  sort(b.begin(), b.end());
  
  for(auto p : b) {
    if(p.first!=n) cout << p.second << " ";
    else cout << p.second << endl;
  }
  
  return 0;
}