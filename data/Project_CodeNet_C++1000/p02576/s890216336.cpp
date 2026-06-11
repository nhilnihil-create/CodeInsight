#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int N, X, t;
  scanf("%d %d %d", &N, &X, &t);

  int y = N/X;

  if(N%X!=0){
    y++;
  }

  int T = y*t;

  printf("%d\n", T);

  return 0;
}