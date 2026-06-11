#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i,s,e) for( i=s;i<e;i++)
#define rfo(i,s,e) for(i=s;i>e;i--)
#define LL long long int
const LL MOD=1e9+7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//            When something is important enough, you do it even if the odds are not in your favor.
long long int power(long long int x, unsigned long long  int y)
{
    long long res = 1,m=y+2;
    x%=m;
    while (y > 0) {
        if (y & 1)
            res = res * x%m;
        x = x * x%m;
        y >>= 1;
    }
    return res;
}
long long int modInverse(long long int a,long long  int m=MOD)
{
            return power(a, m-2);
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // code goes here
    LL t=1;//cin>>t;
    while(t--){
      LL n,i;cin>>n;
      LL fac[10040];fac[0]=1;
      fo(i,1,10040) fac[i]=i*fac[i-1],fac[i]%=MOD;
      LL ans=0;
      fo(i,1,n+1){
        if(n-2*i-1<0||n-3*i<0) break;
        ans+=(fac[n-2*i-1]*modInverse(fac[i-1])%MOD)*modInverse(fac[n-3*i])%MOD;
        ans%=MOD;
      }
      cout<<ans;
    }
    return 0;
}