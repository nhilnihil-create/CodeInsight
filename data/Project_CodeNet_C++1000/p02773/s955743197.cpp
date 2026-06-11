#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  map<string, int> mp;
  for(string str : s) {
    if(mp.count(str)) mp[str]++;
    else mp[str] = 1;
  }
  int max_str = 0;
  for(string str : s) max_str = max(max_str, mp[str]);
  set<string> st;
  for(string str : s) {
    if(mp[str] == max_str) st.insert(str);
  }
  for(string s : st) cout << s << endl;
  return 0;
}