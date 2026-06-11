#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  
  int ans = 0;
  for(int i = 1; i <= k; i++){
    if(i <= a){
      ans += 1;
    }else if(i <= b + a){
      ans += 0;
    }else{
      ans -= 1;
    }//else
  }//for
  
  cout << ans << endl;
}