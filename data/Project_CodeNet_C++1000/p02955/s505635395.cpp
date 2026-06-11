#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
using namespace std;

#define N 502
#define M 1000000
int A[N],tmp[N];
int dv[M];
void solve() {
  int n,k;scanf("%d %d ",&n,&k);
  int sum = 0,pos=0;
  for(int i=1;i<=n;++i) scanf("%d ", &A[i]),sum += A[i];

  for(int i=1;i*i<=sum;++i) {
    if(sum%i==0) {
      dv[pos++] = i;
      if(i*i!=sum) {
        dv[pos++] = sum/i;
      }
    }
  }
  sort(dv,dv+pos);
  for(int i=pos-1;i;--i) {
    int val = dv[i], len = 0,u;
    long long tmpSum = 0;
    for(int j = n;j;--j) {
      if(A[j]%val==0) continue;
      u= val - (A[j]%val);
      tmpSum += u;
      tmp[len++] = val - u;
    }
    long long minValue = 0;
    if(len>0) {
      sort(tmp,tmp+len);
      long long need = tmpSum/val;
      for(int j=0;j<need;++j) {
        minValue += tmp[j];
      }
    }
    if(minValue<=k) {
      printf("%d\n", val);
      return;
    }
  }
  printf("1\n");
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
