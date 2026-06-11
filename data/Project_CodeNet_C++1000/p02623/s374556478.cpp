#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
using ll = long long;

int main() {
  int n,m,k;
  cin >> n >> m >> k ;
  vector<int>a(n),b(m);
  rep(i,n) cin >> a.at(i);
  rep(i,m) cin >> b.at(i);
  vector<ll>suma(n+1),sumb(m+1);//引数冊読むのにかかる時間
  int ans =0;
  rep(i,n+1) {
    if (i==0) suma.at(i)=0;
    else suma.at(i)=suma.at(i-1)+a.at(i-1);
  }
  rep(i,m+1) {
    if (i==0) sumb.at(i)=0;
    else sumb.at(i)=sumb.at(i-1)+b.at(i-1);
  }
  rep(i,n+1) {
    int left=0,right=m+1,mid;
    ll t=k-suma.at(i);
    if (t<0) {
      break;
    }
    else {
      while (left<right-1) {
        mid = (left+right)/2;
        if (sumb.at(mid)>t) right=mid;
        if (sumb.at(mid)<t) left=mid;
        if (sumb.at(mid)==t) left=mid, right=mid+1;
      }
      ans=max(ans,i+left);
    }
  }
  cout << ans << endl;
}
