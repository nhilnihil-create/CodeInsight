#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int n100, n010, n001;
  int ans = 0;
  for(int i=0; i<1000; ++i){
    n100 = i/100;
    n010 = i/10%10;
    n001 = i%10;
    bool f1 = true, f2 = false, f3 = false;
    for(int j=0; j<n; ++j){
      int si = s[j] - '0';
      if(f3 && n001 == si){ ++ans; break;}
      if(f2 && n010 == si){ f3 = true; f2 = false;}
      if(f1 && n100 == si){ f2 = true; f1 = false;}
    }
  }
  cout << ans << endl;
}