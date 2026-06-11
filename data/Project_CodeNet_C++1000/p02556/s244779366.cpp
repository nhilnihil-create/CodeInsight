#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n;
  int x[200005], y[200005];
  cin >> n;
  int mx1=0, mx2=0;
  int mn1=1001001001, mn2=1001001001;
  int mx1i,mx2i,mn1i,mn2i;
  rep(i, n){
    cin >> x[i] >> y[i];
    int tmp1=x[i]+y[i];
    int tmp2=x[i]-y[i];
    if(tmp1>mx1){
      mx1=tmp1;mx1i=i;
    }
    if(tmp2>mx2){
      mx2=tmp2;mx2i=i;
    }
    if(tmp1<mn1){
      mn1=tmp1;mn1i=i;
    }
    if(tmp2<mn2){
      mn2=tmp2;mn2i=i;
    }
  }
  int ans = 0;
  ans = max(x[mx1i]-x[mn1i]+y[mx1i]-y[mn1i], x[mx2i]-x[mn2i]+y[mn2i]-y[mx2i]);
  cout << ans;
  return 0;
}
