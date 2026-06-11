#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//動画解答写し
int main() {
  int n,k;
  cin >>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  rep(ki,k){
    vector<int>b(n+1);
    rep(i,n){
      int l=max(0,i-a[i]);
      int r=min(i+a[i]+1,n);
      b[l]++;b[r]--;
    }
    rep(i,n)b[i+1]+=b[i];
    b.pop_back();//最後の1要素を取る
    if(a==b)break;
    a=b;
  }
  rep(i,n)cout<<a[i]<<endl;//AtCoderではジャッジで空白と改行を区別していない
  return 0;
}