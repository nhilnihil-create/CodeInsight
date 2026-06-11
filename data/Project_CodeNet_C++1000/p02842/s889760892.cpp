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
  int N;
  cin >> N;
  int X=-1;
  for(int i=(int)(N/1.08);i<(int)(N/1.08)+3;i++){
    if((int)(i*1.08)==N){
      X=i;
      break;
    }
  }

  if(X==-1) cout << ":(" << endl;
  else cout << X << endl;

  return 0;
}
