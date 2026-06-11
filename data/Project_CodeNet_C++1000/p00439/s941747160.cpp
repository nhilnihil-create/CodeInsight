#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int N,K;
int a[100010];

int main(){
  int i;

  while(1){
    scanf("%d %d",&N,&K);
    if(N == 0 && K == 0) break;

    REP(i,N) scanf("%d",&a[i]);

    int sum = 0, res = 0;
    REP(i,K){ sum += a[i]; res += a[i]; }
    while(i < N){
      sum += a[i];
      sum -= a[i-K];
      res = max(res,sum);
      i++;
    }

    printf("%d\n",res);
  }

  return 0;
}