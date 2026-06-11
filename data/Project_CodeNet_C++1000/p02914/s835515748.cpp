#include <stdio.h>

int n;
long long int A[100000];

// max_{R} xor_R  + (A xor xor_R)
// max_{R} xor_R and ~A
/*
110
101
011

110
011
011

001
101
110

*/

int main(){
  int i;
  long long int a=0, b, c, z=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%lld", A+i);
    a ^= A[i];
  }
  for(i=0;i<n;i++){
    A[i] &= ~a;
  }

  for(b=1LL<<59;b;b>>=1){
    if(b&a) continue;
    for(i=0;i<n;i++){
      if(A[i]&b) break;
    }
    if(i==n) continue;
    if(!(z&b)) z ^= A[i];
    c = A[i];
    A[i] = 0;
    for(;i<n;i++){
      if(A[i]&b) A[i] ^= c;
    }
  }

  printf("%lld\n", 2*z + a);

  
  return 0;
}
