#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argv, char** argc) {
  int M,D;
  int count = 0;
  cin >> M >> D;
  for(int j=1;j<M+1;j++)
    for(int i=1;i<D+1;i++){
      int d1 = i%10;
      int d10 = i/10;
      if(d1>=2 && d10>=2 && d1*d10 == j) count++;
    }
  printf("%d",count);
  return 0;
}
