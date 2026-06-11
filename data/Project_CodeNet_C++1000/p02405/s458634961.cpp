#include <iostream>
using namespace std;
int main(void){
  int H,W,i,j,n;
  cin >> H;
  cin >> W;

  while(H != 0 && W != 0){
      for(i = 0; i < H; i++){
          for(j = 0; j < W; j++){
              if((i + j) % 2 == 0){
                  cout << "#";
              }
              else{
                  cout << ".";
              }
          }
          cout << endl;
      }
      cin >> H;
      cin >> W;
      cout << endl;
  }
}
