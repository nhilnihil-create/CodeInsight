#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

int main(){
  int H,W;
  string s;

  while(1){
    cin>>H>>W;
    s="";
    if(H==0) break;
    for(int i = 0; i<W; i++){
      s+="#";
    }

    for(int i = 0; i<H; i++){
      cout<<s<<endl;
    }

    cout<<endl;
  }

  return 0;
}