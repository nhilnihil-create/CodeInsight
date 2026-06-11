#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t a,b;
  cin >> a >> b;
  if(a==1||b==1){
    cout << 1 << endl;
  }else{
  int64_t ans=(a*b%2==0?a*b/2:a*b/2+1);
  cout << ans << endl;
  }
  return 0;
}