#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  string s;
  ll ans = 0;
  cin >> n;
  unordered_map<string,int> mp;
  rep(i,n){
    cin >> s;
    sort(s.begin(),s.end());
    mp[s]++;
  }
  for(auto& au:mp){
    ll s = au.second;
    ans += s*(s-1)/2;
  }
  cout << ans << endl;
}