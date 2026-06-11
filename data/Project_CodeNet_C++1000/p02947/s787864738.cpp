#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n; cin >>n;
  map<string, int> mp;
  vector<string> s(n);
  rep(i,n){
    cin >>s[i];
    sort(s[i].begin(), s[i].end());
    mp[s[i]]++;
  }
  ll ans = 0;
  for(string t : s){
    if(mp[t]>1) {
      ans += mp[t]-1;
      mp[t]--;
    }
  }
  cout << ans << endl;
  return 0;
}