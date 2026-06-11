#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  string s;  cin >> s;
  
  int ans = 0;
  for(int i=0; i<1e3; i++){
    int tens = 100, pin = i, pos = 0;
    bool ok = false;
    do{
      while(pos<n && (int)s[pos]-(int)'0'!=(pin/tens%10))  pos++;
      if(pos >= n)  break;
      tens /= 10;
      if(tens == 0)  ok = true;
      pos++;
    }while(tens);
    if(ok)  ans++;
  }

  cout << ans << endl;

  return 0;
}
