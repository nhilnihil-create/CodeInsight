                                                                                                                                #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod ll(1e9+7)
ll exp(ll a,ll b)
{
  if(b==0)
    return 1;
  if(b%2==0)
    return exp(a*a%mod,b/2);
  return a*exp(a*a%mod,(b-1)/2)%mod;
}
int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
   string s;
   cin>>s;
   int n=s.size();
   int cnt=0;
   ll ans=0;
   for(int i=n-1; i>=0; i--){
    if(s[i]=='1'){
      if(cnt==0){
        ans=(ans+exp(3,n-i-1)+2)%mod;
        cnt++;
      }
      else{
        ans=(exp(3,n-i-1)+2*ans)%mod;
      }
    }
   }
   cout<<ans;
   return 0;
}