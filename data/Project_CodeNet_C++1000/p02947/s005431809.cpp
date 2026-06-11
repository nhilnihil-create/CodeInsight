#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0;i < n;i++){
    cin >> s[i];
  }

  long long ans = 0;

  map<string, int> mp;
  
  for (int i = 0;i < n;i++){
    sort(s[i].begin(),s[i].end());
    if (mp.count(s[i])){
      mp[s[i]]++;
      ans += mp[s[i]];
    }
    else{
      mp[s[i]] = 0;
    }
  }
  
  cout << ans << endl;
}