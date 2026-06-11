#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans=0; cin >> n;
  vector<int> p(n);
  
  for(int i=0; i<n; i++) cin >> p.at(i);
  for(int i=0; i<n-2; i++) {
    if(p.at(i) > p.at(i+1) && p.at(i+1) > p.at(i+2)) ans++;
    if(p.at(i) < p.at(i+1) && p.at(i+1) < p.at(i+2)) ans++;
  }
  cout << ans << endl;
}