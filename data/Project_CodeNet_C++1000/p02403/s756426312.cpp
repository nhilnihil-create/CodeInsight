#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
  int H,W;
  for(int c=0;;c++){
    cin >> H >> W;
    if(H+W==0)break;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout << '#';
    }
    cout << endl;
  }
  cout << endl;
}

  return 0;
}