#include <bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin>>x;
  for(int i=x;;i++){
    bool ok=true;
    for(int j=2;j*j<=x;j++){
      if(i%j==0)ok=false;
    }
    if(ok){
      cout<<i<<endl;
      return 0;
    }
  }
  return 0;
}