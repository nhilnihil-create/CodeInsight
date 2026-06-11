#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n; cin>>n;
  vector<ll> v(n);
  vector<ll> dp(n,1);
  int val=sqrt(n);
  vector<int> primes(n+1,1);
  primes[0]=primes[1]=0;
  ll ans=1;
  iota(v.begin(),v.end(),1);
  for(int i=2;i*i<=n;i++){
    if(primes[i]){
    for(int j=i;j<=n;j+=i){
      primes[j]=0; int cnt=0;
      while(v[j-1]%i==0) v[j-1]/=i,cnt++;
      dp[j-1]*=(cnt+1);
    }
    }
  }
  for(int j=2;j<=n;j++){
    if(v[j-1]!=1) dp[j-1]*=2;
    ans+=dp[j-1]*j;
  }
  cout<<ans<<endl;
}
    
      
      
      