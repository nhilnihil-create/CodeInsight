#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  int n;
  while(scanf("%d", &n), n){
    int A = 0;
    int B = 0;

    for(int i = 0; i < n; i++){
      int a, b;
      scanf("%d%d", &a, &b);
      if(a < b) B += a + b;
      if(a > b) A += a + b;
      if(a == b){ A += a; B += b; }
    }

    printf("%d %d\n", A, B);
  }

  return 0;
}