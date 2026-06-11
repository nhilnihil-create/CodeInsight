#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; scanf("%d",&N);
  int X[N], L[N]; pair<int,int> endstart[N];
  for(int i=0; i<N; i++) {
    scanf("%d %d",&X[i],&L[i]);
    endstart[i].first=X[i]+L[i];
    endstart[i].second=X[i]-L[i];
  }
  sort(endstart,endstart+N);
  int ans=1, t=endstart[0].first;
  for(int i=1; i<N; i++) {
    if (t<=endstart[i].second) {
      ans++;t=endstart[i].first;
    }
  }
  printf("%d\n",ans);
}