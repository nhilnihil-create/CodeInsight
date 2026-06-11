#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a; cin >> a;
  if(a>=2000){
    cout << 1 << endl;
    exit(0);
  }
  else{
    for(int x=0; x<20; x++){
      for(int y=0; y<20; y++){
        for(int z=0; z<20; z++){
          for(int t=0; t<20; t++){
            for(int u=0; u<20; u++){
              for(int v=0; v<20; v++){
                if(100*x+101*y+102*z+103*t+104*u+105*v==a){
                  cout << 1 << endl;
                  exit(0);
                }
              }
            }
          }
        }
      }
    }
  }
  cout << 0 << endl;
}