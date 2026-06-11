#include<iostream>
using namespace std;

int main(){
  int i, j, x, y;

  while(1){
    cin >> x >> y;
    if(x == 0 || y == 0) break;

    for(i = 0; i < x; i++){
      for(j = 0; j < y; j++){
        if(i == 0 || i == x-1 || j == 0 || j == y-1 )  cout << '#';
        else                                           cout << '.';
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}