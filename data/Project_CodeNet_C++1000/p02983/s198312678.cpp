#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)

int main(){
  int l,r;	cin >> l >> r;
  int right=min(l+2018,r);
  
  int ans=2019;
  for(int i=l;i<=right;i++){
    for(int j=i+1;j<=right;j++){
      int a=i%2019;
      int b=j%2019;
      ans=min(ans,(a*b)%2019);
    }
  }
  cout << ans;
}