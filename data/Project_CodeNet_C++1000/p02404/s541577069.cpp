#include <iostream>
using namespace std;

void frm(int H, int W){
  for (int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        if (i == 0 || i == H-1 || j == 0 || j == W - 1){
          cout << '#';
        }else{
          cout << '.';
        } 
      } 
      cout << endl;     
  }
}

int main(){
  int H,W;

  while(1){
    cin >> H >> W;
    if(H == 0 && W == 0) return 0;
    
    frm(H, W);
    cout << endl;
  }
}