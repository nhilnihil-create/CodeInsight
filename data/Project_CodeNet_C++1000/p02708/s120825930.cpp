#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,k;
  cin >> n >> k;
  ll i,ans=0,j,mod=1e9+7;
  for(i=k;i<=n+1;i++){
    ll sum=0,sum1=0;
    sum=i*(i-1)/2;
    sum1=i*(n+n-i+1)/2;
    ans+=sum1-sum+1;
    ans%=mod;
  }
  cout << ans;
}