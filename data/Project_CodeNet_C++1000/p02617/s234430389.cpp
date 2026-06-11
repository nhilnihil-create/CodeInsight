#include<bits/stdc++.h>
using namespace std;
int main(){
long long n, l, r,ans=0;
cin >> n;
ans = (n*(n+1)*(2*n+1) + 3*(n+1)*n)/12;
for(int i=0;i<n-1;i++){
  cin >> l >> r;
  if(l > r)swap(l,r);
  ans-= l * (n-r+1);
}
  cout << ans;
}
  