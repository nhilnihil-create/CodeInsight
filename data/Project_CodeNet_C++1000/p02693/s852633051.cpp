#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,a,b;
  bool ok=0;
  cin >> k >> a >> b;
  for(int i=a;i<=b;i++){
    if(i%k==0) ok=1;
  }
  if(ok==1) cout <<"OK";
  else cout << "NG";
  return 0;
}