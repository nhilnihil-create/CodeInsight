#include <bits/stdc++.h>
using namespace std;
 
int main() {

  int N;
  scanf("%d", &N);

  int X = N%1000;

  if(X==0){
      printf("0\n");
  }else{
      printf("%d\n", 1000-X);
  }

  return 0;
}