#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
  int W,H,c=0;
  while(c==0){
  cin >> H >> W;
  if(H+W==0)break;
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      if(i%2==0 && j%2==0)cout << '#';
      else if(i%2!=0 && j%2!=0)cout << '#';
      else cout << '.';
    }
    cout << endl;
  }
  cout << endl;
}

  return 0;
}