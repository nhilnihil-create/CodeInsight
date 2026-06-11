#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define SZ(a) int((a).size())
#define FOR(var,a,b) for(int var=(a);var<(b);var++)
#define REP(var,n) FOR(var,0,n)
#define INT(n) int n;scanf("%d",&n);

int main(){
  INT(n);
  printf("%d:", n);
  FOR(i, 2, 100000){
    if (n < i * i){break;}
    while (n % i == 0){
      printf(" %d", i);
      n /= i;
    }
  }
  if (1 < n){printf(" %d", n);}
  printf("\n");
  return 0;
}