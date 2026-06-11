#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n;
  cin >> n;
  int w[n], total=0;
  rep(i,n){
    cin >> w[i];
    total += w[i];
  }
  int ans  =total,tmp=0;
  rep(i,n-1){
    tmp += w[i];
    if(total-2*tmp<0){
      ans = min(2*tmp-total,ans);
    } else{
      ans = min(-2*tmp+total,ans);
    }
  }
  cout << ans << endl;
}