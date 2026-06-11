#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w,a,b,i,j;
  cin >> h >> w >> a >> b;
  for(i=0;i<h;i++){
    if(i<b){
      for(j=0;j<w;j++){
        if(j<a){
          cout << 1;
        }else{
          cout << 0;
        }
      }
      cout << endl;
    }else{
      for(j=0;j<w;j++){
        if(j<a){
          cout << 0;
        }else{
          cout << 1;
        }
      }
      cout << endl;
    }
  }
}