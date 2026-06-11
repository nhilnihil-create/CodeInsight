#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >>N>>M;
  
  bool can=false;
  for(int i=1;i<=10099;i++){
    if(i*8/100==N && i*10/100==M ){
      can=true;
      cout << i <<endl;
      break;
    }
  }
  if(!can){
    cout << -1 <<endl;
  }
}
