#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  
  int ans = 0;
  bool flag = true;
  rep(i,1000){
    int at = floor(i*0.08);
    int bt = floor(i*0.10);
    if(at==a && bt == b){
      ans = i;
      flag = false;
      break;
    }
  }
  if(flag){
    cout << "-1" << endl;
  }else{
    cout << ans << endl;
  }
}
