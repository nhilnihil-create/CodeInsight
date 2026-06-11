#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;
int bitCount(unsigned int bits) {
    int cnt = 0;
    for(unsigned int mask = 1; mask != 0; mask<<=1) {
        if( (bits & mask) != 0 )
            ++cnt;
    }
    return cnt;
}

int main() {
  ll int n;
  cin >> n;
  vector<ll int> in(n);
  rep(i, n) cin >> in[i];
  
  ll int all = 0;
  rep(i, n) all = all ^ in[i];
  
  rep(i, n) {
    ll int ans = all ^ in[i];
    cout << ans << " ";
  }
  
  cout << endl;
  return 0;
}
