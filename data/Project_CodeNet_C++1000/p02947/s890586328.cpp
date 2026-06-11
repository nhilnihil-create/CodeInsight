#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  string s;
  map<string, int> a;
  for(int i=0; i<n; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    a[s]++;
  }
  
  int64_t ans = 0;
  vector<int64_t> memo(100001, -1);
  for(pair<string, int64_t> p : a) {
    if(p.second>1) ans += p.second*(p.second-1)/2;
  }
  
  cout << ans << endl;
  return 0;
}