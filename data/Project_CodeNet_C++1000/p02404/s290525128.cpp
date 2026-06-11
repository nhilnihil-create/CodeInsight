#include<iostream>
using namespace std;

int main(){
  while(1){
    int H, W;
    cin >> H >> W;
    if(H == 0 && W == 0) break;
    for(int i = 1; i <= H; i++){
      for(int j = 1; j <= W; j++){
        if(i != 1 && j != 1 && i != H && j != W){
          cout << ".";
        }else{
          cout << "#";
        }
      }
    cout << endl;
    }
  cout << endl;
  }

  return 0;
}