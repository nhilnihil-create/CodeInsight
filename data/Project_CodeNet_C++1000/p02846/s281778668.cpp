#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>

int main(){
  int T1, T2;
  scanf("%d", &T1);
  scanf("%d", &T2);
  long long A1, A2, B1, B2;
  scanf("%lld", &A1);
  scanf("%lld", &A2);
  scanf("%lld", &B1);
  scanf("%lld", &B2);
  long long A = A1*T1 + A2*T2;
  long long B = B1*T1 + B2*T2;
  //printf("%lld %lld\n", A, B);
  if (A == B){
    printf("infinity\n");
  } else if (A>B){
    long long D = A-B;
    if (A1>B1){
      printf("0\n");
    } else {
      long long d = B1*T1 - A1*T1;
      long long ans = 2*(((d+D-1)/D)-1) + 1;
      if (d%D==0) ans++;
      printf("%lld\n", ans);
    }
  } else if (A<B){
    long long D = B-A;
    if (A1<B1){
      printf("0\n");
    } else {
      long long d = A1*T1 - B1*T1;
      long long ans = 2*(((d+D-1)/D)-1) + 1;
      if (d%D==0) ans++;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
 