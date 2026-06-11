#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,i,j;
  cin >> k >> i >> j;
  bool t=true;
  for(int d=i;d<=j;d++){
    if(d%k==0){
      t=false;
      cout << "OK" <<endl;
      break;
    }
  }
  if(t)cout << "NG" << endl;
}
  
