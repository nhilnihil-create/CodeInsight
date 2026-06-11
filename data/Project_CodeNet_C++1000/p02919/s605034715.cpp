#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
#include <set>
using namespace std;

#define N 100005
#define mod 1000000007

int p[N];
int lmini[N],lmaxi[N];
int rmini[N],rmaxi[N];
bool hasLeft[N],hasRight[N];
void solve() {
  int n;scanf("%d ",&n);
  vector<pair<int,int> >in;
  for(int i=1;i<=n;++i) {
    scanf("%d ",&p[i]);
    in.push_back(make_pair(p[i],i));
  }
  sort(in.begin(),in.end());
  set<int> s;

  for(int i=n-1;i>=0;--i) {
    int ind = in[i].second;
    s.insert(ind);
    set<int>::iterator it = s.find(ind);
    if(it== s.begin()) {
      hasLeft[ind] = false;
      lmini[ind] = ind;
    } else {
      hasLeft[ind] = true;
      --it;
      lmini[ind] = ind - *it;
      if(it!=s.begin()) {
        --it;
        lmaxi[ind] = ind - *it;
      } else {
        lmaxi[ind] = ind;
      }
    }
    it = s.find(ind);
    ++it;
    if(it==s.end()) {
      hasRight[ind] = false;
      rmini[ind] = n+1 - ind;
    } else {
      hasRight[ind] =true;
      rmini[ind] = *it - ind;
      ++it;
      if(it==s.end()) {
        rmaxi[ind] = n+1 - ind;
      } else {
        rmaxi[ind] = *it - ind;
      }
    }
  }
  long long ret = 0;
  for(int i=1;i<=n;++i) {
    if(p[i]==n) continue;
    long long tmp = 0;
    if(hasLeft[i]) {
      tmp = (long long)(lmaxi[i]-lmini[i])*rmini[i];
    }
    if(hasRight[i]) {
      tmp += (long long)(rmaxi[i] - rmini[i])*lmini[i];
    }
    tmp *= p[i];
    ret += tmp;
  }
  printf("%lld\n", ret);
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
