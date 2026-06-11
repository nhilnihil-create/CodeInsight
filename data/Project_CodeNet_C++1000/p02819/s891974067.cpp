#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=n;
  bool ok=false;
  for(int i=0;i<100000;i++){
    ok=true;
    for(int j=2;j<sqrt(ans);j++){
      if(ans%j==0)
        ok=false;
    }
    if(ok)
      break;
    else
      ans++;
  }
  cout << ans << endl;
  return 0;
}