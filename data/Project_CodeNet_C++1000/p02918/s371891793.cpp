#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> dir(n, 0);
  int len = 0;
  dir[0] = 1;
  for(int i=1; i<n; i++){
    if(s[i] == s[i-1]) dir[len]++;
    else {
      len++;
      dir[len]++;
    }
  }

  int ans = 0;
  for(int i=0; i<=len; i++){
    ans += dir[i] - 1;
  }
  if(len > 2*k) ans += 2*k;
  else ans = n-1;
  cout << ans << endl;
}
