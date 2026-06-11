#include<bits/stdc++.h>
using namespace std;
int main(){
  long n,k;
  cin >> n >> k;
  int a[n];
  int i,j;
  for(i=0;i<n;i++)cin>>a[i];
  long ans = 0;
  long const mod = 1e9+7;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(a[i]>a[j]){
        if(i>j){
          ans += k*(k-1)/2;
        }else if(i<j){
          ans += k*(k+1)/2;
        }
      }
      ans %= mod;
    }
  }
  cout<<ans<<endl;
}
