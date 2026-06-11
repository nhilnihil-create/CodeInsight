#include<bits/stdc++.h>
using namespace std;

int main(){
  int X, Y;
  cin >> X >> Y;
  int ans=0;
  if(X==1 && Y==1){
    ans+=400000;
  }
  if(X==1 || X==2 || X==3){
    ans+=100000+(3-X)*100000;
  }
  if(Y==1 || Y==2 || Y==3){
    ans+=100000+(3-Y)*100000;
  }
  cout << ans << endl;
  return 0;
}