#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){

  ll n,k;
  cin>>n>>k;
  ll s[n+1];
  s[0]=0;
  rep(i,n){
    s[i+1]=s[i]+i+1;
  }
  ll ans=0;
  for(int i=k;i<=n+1;i++){
    if(i==n+1){
      ans+=1;
    }
    else{
      ans+=(s[n]-s[n-i])-s[i-1]+1;
    }
  }
  cout<<ans%1000000007<<endl;
}
