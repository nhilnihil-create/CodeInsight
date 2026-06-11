#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, K;
  scanf("%d %d %d %d", &A, &B, &C, &K);

  if(K <= A) printf("%d\n", K);
  else if(K <= A + B) printf("%d\n", A);
  else  printf("%d\n", A - (K - (A + B)));
}