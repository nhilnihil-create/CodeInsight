#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
using namespace std;

#define N 200002
int a[N],b[N];
void solve() {
  int n;scanf("%d",&n);
  for(int i=0;i<n;++i) {
    scanf("%d",&a[i]);
  }
  long long ret = 0;
  priority_queue<pair<int,int> >pq;
  for(int i=0;i<n;++i) {
    scanf("%d",&b[i]);
    if(a[i]>b[i]) {
      printf("-1\n");
      return;
    }
    pq.push(make_pair(b[i],i));
  }
  while(!pq.empty()) {
    int ind = pq.top().second;
    int val = b[ind];
    pq.pop();
    if(val==a[ind]) {
      continue;
    }
    int maxi = max(b[(ind+n-1)%n], b[(ind+1)%n]);
    maxi = max(maxi,a[ind]);
    int g = b[(ind+n-1)%n] + b[(ind+1)%n];
    int diff = val - maxi;
    if(b[ind]-g<a[ind]) {
      continue;
    }
    long long add = max(1,diff/g);
    long long tmp = b[ind] - add*g;
    if(tmp<a[ind]) {
      break;
    }
    b[ind] -= g*add;
    ret += add;
    pq.push(make_pair(b[ind],ind));
  }
  for(int i=0;i<n;++i) {
    if(a[i]!=b[i]) {
      ret = -1;
      break;
    }
  }
  printf("%lld\n", ret);
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
