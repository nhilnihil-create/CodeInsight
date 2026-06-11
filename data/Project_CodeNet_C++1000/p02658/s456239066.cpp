#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  __float128 x=1;
  int64_t a=1,b;
  bool ok=true;
  for(int i=0;i<n;i++){
    cin >> b;
    if(b==0){
      cout << 0 << endl;
      return 0;
    }
    a*=b;
    x*=b;
    if(x>1000000000000000000||a>1000000000000000000)
      ok=false;
  }
  cout << (ok?a:-1) << endl;
  return 0;
}