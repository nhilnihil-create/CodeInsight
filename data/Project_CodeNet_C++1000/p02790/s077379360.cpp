#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a,b;
  cin >> a >> b;
  
  string ans = "";
  if(a <= b){
    int tmp = b - '0';
    while(tmp-- > 0){
      ans += a;
    }
  }else{
    int tmp = a - '0';
    while(tmp-- > 0){
      ans += b;
    }
  }
  
  cout << ans << endl;
}