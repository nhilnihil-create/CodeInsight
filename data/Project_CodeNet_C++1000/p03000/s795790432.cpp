#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n, x;
  cin >> n >> x;
  int l[n];
  rep(i,n){
    cin >> l[i];
    if(i!=0)
      l[i]+=l[i-1];
  }
  int ans =0;
  rep(i,n)
    if(l[i]<=x)
      ans++;
  cout << ans+1 << endl;
  
}