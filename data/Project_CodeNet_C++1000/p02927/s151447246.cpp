#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  int m,d;
  cin >> m>> d ;
  
  int c=0;
  for(int i=1;i<=m;i++){
    if(d<22){
      break;
    }
    for(int j=22;j<=d;j++){
      if(j%10==0||j%10==1) {
        continue;
      }
      if(((j%10)*(j/10))==i){
        c++;
      }
    }
  }
  
  cout << c << endl;
}