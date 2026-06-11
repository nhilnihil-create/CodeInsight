#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const LL M = 1e9 + 7;

int main() {
  string S;
  cin >> S;
  reverse(begin(S), end(S));

  LL p = 1;
  vector<LL> dp(13);
  dp[0] = 1;
  for(auto c: S) {
    vector<LL> nex(13);
    if(c == '?') for(auto k=0; k<10; ++k) for(auto i=0; i<13; ++i) (nex[(i+k*p)%13] += dp[i])%= M;
    else         for(auto i=0; i<13; ++i) (nex[(i+(c-'0')*p)%13] += dp[i]) %= M;
    dp = nex;
    (p *= 10) %= 13;
  }
  cout << dp[5] << endl;
}
