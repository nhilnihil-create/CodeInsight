//mapの使い方

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  map<string, int> mp;  //集計用
  rep(i,N){
    string s;
    cin >> s;
    sort(all(s));
    mp[s] ++;
  }
  ll ans = 0;
  for (auto &p : mp){
    ll s = p.second;
    ans += s * (s - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
