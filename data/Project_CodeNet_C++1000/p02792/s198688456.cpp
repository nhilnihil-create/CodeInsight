#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<string,int> mp;
  for(int i=1;i <= n;i++) {
    string s = to_string(i);
    char first = s[0];
    char second = s[s.length() - 1];
    s.clear();
    s += first;
    s += second;
    mp[s]++;
  }
  long long ans = 0;
  for(pair<string,int> p : mp) {
    string s = p.first;
    int freq = p.second;
    if(s[0] == s[1]) {
      ans += (long long) freq * freq;
    }
    else {
      swap(s[0],s[1]);
      ans += (long long) freq * mp[s];
    }
  }
  cout << ans << "\n";
}