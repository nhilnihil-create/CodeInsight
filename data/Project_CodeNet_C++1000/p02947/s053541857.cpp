#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0;i < n;i++){
    cin >> s[i];
  }
  
  for (int i = 0;i < n;i++){
    sort(s[i].begin(), s[i].end());
  }
  sort(s.begin(),s.end());
  
  /*for (int i = 0;i < n;i++){
    cout << s[i] << endl;
  }*/
  
  long long ans = 0;
  long long c = 0;
  
  for (int i = 0;i < n;i++){
    if (i != n){
      if (s[i] == s[i+1]){
        c++;
        continue;
      }
      else{
        ans += (c+1)*c/2;
        c = 0;
      }
    }
    else{
      ans += (c+1)*c/2;
      c = 0;
    }
  }
  
  cout << ans << endl;
}