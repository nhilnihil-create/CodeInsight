#include <bits/stdc++.h>
using namespace std;

int zalgo(string s, int x){
  s = s.substr(x);
  int n = s.size();
  vector<int> a(n, 0);
  int l = -1, r = -1;
  for(int i=1; i<n; ++i){
    int &cnt = a[i];
    if(l != -1){
      cnt = min(a[i-l], r-i);
      cnt = max(0, cnt);
    }
    while(i + cnt < n && s[cnt] == s[i+cnt]) ++cnt;
    if(r < i+cnt){
      l = i;
      r = i+cnt;
    }
  }
  a[0] = n;
  int ans = 0;
  for(int i=0; i<n; ++i){
    if(a[i] <= i) ans = max(ans, a[i]);
  }
  return ans;
}

int main(){
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for(int i=0; i<n; ++i){
    ans = max(ans, zalgo(s,i));
  }
  cout << ans << endl;
}