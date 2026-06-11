//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_5_A
#include <iostream>
using namespace std;
int main(){
  int H, W;
  while (cin >> H >> W) {
    if(H == 0 && W == 0){
      break;
    }
    else{
        for(int i = 0; i < W; i++){
          cout << "#";
        }
        cout << endl; //???????????????
        for(int j = 0; j < H-2; j++){
          cout << "#";
          for(int i=0; i< W-2; i++){
            cout << ".";
          }
          cout << "#" << endl;
        }
      //???????????????
      for(int i = 0; i < W; i++){
        cout << "#";
      }
      cout << endl;
    }
    cout << endl;
  }
}