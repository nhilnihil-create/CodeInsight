#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int n,all=0,wa=0;
  cin >> n;
  int w[n],ans[n];
  for(int i=0;i<n;++i) {
    cin >> w[i];
    all+=w[i];
  }
  for(int i=0;i<n;++i) {
    for(int t=0;t<i+1;++t) {
      wa += w[t];
    }
    ans[i]=abs(wa-(all-wa));
    wa=0;
  }
  sort(ans,ans+n);
  cout << ans[0] << endl;
}