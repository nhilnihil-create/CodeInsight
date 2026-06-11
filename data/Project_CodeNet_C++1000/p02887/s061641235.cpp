#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 1;
  for (int i = 1;i < n;i++){
    if (s[i-1] == s[i]){
      continue;
    }
    else{
      ans++;
    }
  }
  
  cout << ans << endl;
}