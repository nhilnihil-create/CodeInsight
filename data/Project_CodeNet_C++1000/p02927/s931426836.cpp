#include <iostream>
using namespace std;

int main(){
  int m,d;
  int res = 0;
  cin >> m >> d;
  if (d < 22){
    res = 0;
  }else{
    int a = d % 10;
    int b = d / 10;
    for (int i = 2; i <= b; i++){
      if (i == b){
        for (int j = 2; j <= a; j++){
          if (i*j <= m){
            res += 1;
          }
        }
      }else{
        for (int j = 2; j <= 9; j++){
          if (i*j <= m){
            res += 1;
          }
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}