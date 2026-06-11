#include <bits/stdc++.h>
using namespace std;
using Int = uint64_t;
using Float = double;

int main()
{
  Int N, P;
  cin >> N >> P;
  string S;
  cin >> S;

  if (P==2 || P==5) {
    uint64_t ans = 0;
    for(int i=0; i<N; i++) {
      if (Int(S[i]-'0') % P == 0) {
        ans += i+1;
      }
    }
    cout << ans << endl;
    return 0;
  }
  
  auto ms = vector<Int>(N+1,0);
  int mul = 1;
  for(int i=N-1; i>=0; i--) {
    ms[i] = (Int(S[i]-'0') * mul + ms[i+1]) % P;
    mul = (mul*10) % P;
  }
  
  auto d = unordered_map<int, int>();
  for(auto&& m : ms) {
    if (d.find(m) == d.end()) {
      d[m] = 1;
    } else {
      d[m]++;
    }
  }
  
  uint64_t ans = 0;
  for(auto&& kv : d) {
    if (kv.second >= 2) {
      ans += uint64_t(kv.second) * uint64_t(kv.second - 1) / 2; 
    }
  }
  cout << ans << endl;
  
  return 0;
}
