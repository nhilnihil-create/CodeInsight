#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

int main(){
  int H,W;
  string s,s_inside;

  while(1){
    cin>>H>>W;
    s="";
    s_inside="#";
    if(H==0) break;

    for(int i = 0; i<W; i++){
      s+="#";
    }
    for(int i = 1; i<W-1; i++){
      s_inside += ".";
    }
    s_inside += "#";

    cout<<s<<endl;
    for(int i = 1; i<H-1; i++){
      cout<<s_inside<<endl;
    }
    cout<<s<<endl;

    cout<<endl;
  }

  return 0;
}