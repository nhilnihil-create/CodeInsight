// input: HW
// output: chessboard, left-top is #
// # and .

#include <iostream>

using namespace std;

int main(void){
  int H, W;
  while(1){
    cin >> H >> W;
    if(H == 0 && W == 0) break;
    for(int h=0; h<H; h++){
      for(int w=0; w<W; w++){
        if((w%2 == 1 && h%2 == 1) || (w%2 == 0 && h%2 == 0)) cout << "#";
        else cout << ".";
      }
      cout << endl;
    }
    cout << "\n";
  }
  return 0;
}
