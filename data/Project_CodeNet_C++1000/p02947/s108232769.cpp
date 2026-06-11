#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;

int main() {
  int n; cin >> n;
  map<string, int> mp;
  ll ans = 0;
  rep(i,n){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    mp[s]++;
  }
  for(auto p : mp){
    ans += (ll)p.second*(p.second-1)/2;
  }
  cout << ans << endl;
  return 0;
}