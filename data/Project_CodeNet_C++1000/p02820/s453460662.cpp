#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  int k; cin >> k;
  map<char,int> mp;
  cin >> mp['s'] >> mp['p'] >> mp['r'];
  string s; cin >> s;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    if(i < k){
      ans += mp[s[i]];
    } else {
      if(s[i] == s[i-k]){
        s[i] = 'a';
      } else {
        ans += mp[s[i]];
      }
    }
  }
  cout << ans << endl;
}