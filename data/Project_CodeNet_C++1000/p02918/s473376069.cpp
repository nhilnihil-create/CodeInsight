#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  string s;
  cin >> n >> k >> s;
  bool rev = false;
  int ans = 0;
  for(int i=0; i<n-1; ++i){
    if (s[i] == s[i+1]) ++ans;
    else if (k>0){
      if(rev){
        --k;
        ans += 2;
        rev = false;
      }else{
        rev = true;
      }
    }
  }
  if(k>0 && rev) ++ ans;
  cout << ans << endl;
}