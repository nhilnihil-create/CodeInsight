#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int64_t ans = 0;
  
  map<string, int64_t> memo;
  
  for (int i = 0; i < N; i++) {
    
    string s; cin >> s;
    
    sort(s.begin(), s.end());
    
    memo[s]++;
    
  }
  
  for (auto x : memo) {
    
    int64_t tmp = x.second;
    
    ans += tmp * (tmp - 1) / 2;
    
  }
  
  cout << ans << endl;
  
}