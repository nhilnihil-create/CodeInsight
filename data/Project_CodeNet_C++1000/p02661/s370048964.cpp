#include <bits/stdc++.h>
using namespace std;
#define LL long long

int n;
LL A[200005], B[200005];

int main(){
  scanf("%d",&n);
  for ( int i = 0; i < n; i++ ) scanf("%lld %lld",&A[i],&B[i]);
  sort(A,A+n);
  sort(B,B+n);
  if ( n & 1 ){
    printf("%lld\n",B[n/2] - A[n/2] + 1 );
  } else {
    LL a = (A[n/2-1] + A[n/2]);
    LL b = (B[n/2-1] + B[n/2]);
    printf("%lld\n",b-a+1);
  }
  return 0;
}





