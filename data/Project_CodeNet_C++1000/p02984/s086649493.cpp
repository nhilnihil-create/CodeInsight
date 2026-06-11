#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> mou(n);
  for(int i=0; i<n; ++i) cin >> mou[i];
  int l=-1, r=min(mou[0],mou[n-1])+1;
  vector<int> ans(n);
  while(l<r-1){
    int mid = (l+r)/2;
    ans[0] = mid;
    bool ansis = false;
    for(int i=1; i<n; ++i){
      ans[i] = mou[i-1] - ans[i-1];
      if(ans[i] < 0){
        if(i%2) r = mid;
        else l = mid;
        break;
      }
      if(i==n-1){
        int x = mou[n-1] - ans[n-1] - ans[0];
        if(x==0) ansis = true;
        else if(x<0) r = mid;
        else l = mid;
      }
    }
    if(ansis) break;
  }
  for(int i=0; i<n; ++i){
    if(i==n-1) cout << ans[i]*2 << endl;
    else cout << ans[i]*2 << " ";
  }
}
