//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_5_C
#include <iostream>
using namespace std;

bool isEven(int n){
  if(n % 2 ==0) return true;
  else return false;
}

void write_sh(int n){
  //#???????§???????
    for(int i = 0; i< n/2; i++){
      cout << "#.";
    }
    if(isEven(n)){
      cout << endl;
    }
    else{
      cout << "#" << endl;
    }
}

void write_dot(int n){
  //.???????§???????
    for(int i = 0; i < n/2; i++){
      cout << ".#";
    }
    if(isEven(n)){
      cout << endl;
    }
    else{
      cout << "." << endl;
    }
}

int main(){
  int H, W;
  while (cin >> H >> W) {
    if(H == 0 && W == 0){
      break;
    }
    else{
        for(int i = 0; i < H/2; i++){
          write_sh(W);
          write_dot(W);
        }
        if(isEven(H+1)){
          write_sh(W);
        }
      }
      cout << endl;
    }
}