#include<bits/stdc++.h>
using namespace std;
int main(){
  int x; 
  cin >> x;
  while(true){
    bool ok=1;
    for(int i=2;i<=sqrt(x);i++){
      if(x%i==0){ok=0; break;}
    }
    if(ok==1){cout << x;return 0;}
    x++;
  }
  return 0;
}