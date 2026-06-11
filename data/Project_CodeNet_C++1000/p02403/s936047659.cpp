#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int H,W;
  while(1){
  cin >> H >> W;
  if(H==0 && W==0)
    break;
  REP(i,H){
    REP(j,W)
     cout <<"#";
  cout << endl;
  }
  cout << endl;
  }
}