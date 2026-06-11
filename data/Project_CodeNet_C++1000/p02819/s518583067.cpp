#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll x;
  cin >> x;
  
  if(x == 2){
    cout << 2 << endl;
    return 0;
  }else if(x % 2 == 0){
    x++;
  }
  
  bool flag = true;
  int ans = 0;
  for(int i = x; ;i += 2){
    for(int j = 2; j <= i/2; j++){
      if(i % j == 0){
        flag = false;
        break;
      }
    }//for
    if(flag == true){ 
      ans = i;
      break;
    }
    flag = true;
  }//for
  
  cout << ans << endl;
}