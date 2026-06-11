#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <tuple>
#include <algorithm>
#include <array>
using namespace std;
using ll = long long;
#define rep(i,n) for(decltype(n) i=0; i<n; ++i)
inline constexpr ll Inf = (1ULL << 62) -1;

int main() {
    string s,t;
    cin >> s >> t;
    ll ans=0;
  	rep(i,s.size())
      if (s[i] != t[i]) ++ans;
  
    cout << ans << endl;
    return 0;
}
