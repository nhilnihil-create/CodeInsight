#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  int ans=0;
  int x;
  x=min(a,k);
  ans+=x;
  k-=x;
  if(k<=0){
    cout << ans;
    return 0;
  }
  x=min(b,k);
  k-=x;
  if(k<=0){
    cout << ans;
    return 0;
  }
  x=min(c,k);
  ans-=x;
  cout << ans;
}