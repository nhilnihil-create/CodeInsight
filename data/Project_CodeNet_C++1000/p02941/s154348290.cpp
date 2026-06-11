#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
using namespace std;

#define N 200000
int a[N],b[N];
void solve() {
  int n;scanf("%d",&n);
  for(int i=0;i<n;++i) scanf("%d",&a[i]);
  priority_queue<pair<int,int> > pq;
  long long ret = 0;
  for(int i=0;i<n;++i) scanf("%d",&b[i]), pq.push(make_pair(b[i],i));
  while(!pq.empty()) {
    int v = pq.top().first, ind =pq.top().second;
    pq.pop();
    if(v<=a[ind]) {
      continue;
    }
    int maxi = max(b[(ind+n-1)%n],b[(ind+1)%n]);
    maxi = max(maxi,a[ind]);
    int t = b[(ind+n-1)%n] + b[(ind+1)%n];
    int diff = v - maxi;
    int add = max(1, diff/t);
    ret = ret + add;
    v -= add*t;
    b[ind] = v;
    if(v<a[ind]) {
      break;
    }
    if(v<=a[ind]) {
      continue;
    }
    pq.push(make_pair(b[ind],ind));
  }
  bool isGood = true;
  for(int i=0;i<n;++i) {
    if(a[i]!=b[i]) {
      isGood = false;
    }
  }
  if(isGood) {
    printf("%lld\n", ret);
  } else {
    printf("-1\n" );
  }
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
