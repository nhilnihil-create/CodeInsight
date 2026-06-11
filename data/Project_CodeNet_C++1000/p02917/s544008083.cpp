#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
#define sz(s) (int)(s.size())
#define mod 1000000007

using namespace std;

int main(){

  int n;

  //入力を受け取る
  cin >> n;
  int b[n-1];

  rep(i,0,n-2)cin >> b[i];
  
  long long ans = b[0];
  rep(i,1,n-2){
  //b_i, b_{i+1}のうち小さい方がA_iの最大値となる
  ans += min(b[i-1],b[i]);
  }
  ans += b[n-2];
  
  cout << ans << endl;

  return 0;

}