#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,M;
  while(1) {
    cin >> H >> M;
    for ( int i = 0; i < H; i++ ){
    for ( int j = 0; j < M; j++ ){
        if(i*j>=1&&i<=(H-2)&&j<=(M-2)){
           cout<<".";
        }
        else {
          cout<<"#";
        }
}
    cout<<endl;
    if(H==0&&M==0) {
      break;
    }
}
    if(H==0&&M==0) {
      break;
    }
    cout<<endl;
}
           }
            

