#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;


int main(){
  long double max,x;
  long long yokin;
  cin >> x;
  yokin = 100;
  max = pow(10,18);
  
  for (int i=1; i<max; i++){
    //yokin  = floor(yokin*1.01);
    yokin += yokin/100;
    if (yokin >= x){
      cout << i;
      break;
    }
  }
}