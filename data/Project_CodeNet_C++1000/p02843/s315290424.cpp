#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int X;
  cin >> X;
  if(X<100){
    cout << 0 << endl;
    return 0;
  }
  int new_X=X%100;
  int N_PC=new_X/5;
  new_X=new_X%5;
  int temp_X=105*N_PC+100+new_X;
  if(new_X==0) temp_X=105*N_PC;
  if(X<temp_X) cout << 0 << endl;
  else cout << 1 << endl;

  return 0;
}
