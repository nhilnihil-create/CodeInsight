#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i,s,e) for( i=s;i<e;i++)
#define rfo(i,s,e) for(i=s;i>e;i--)
#define LLI long long int
#define LI long int 
const LI MOD=1e9+7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//            When something is important enough, you do it even if the odds are not in your favor.
LLI fac[(LI)1e6+4];
long long int power(long long int x, unsigned long long  int y, unsigned  long long int m)
{
    long long res = 1;
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
            return power(a, m-2, m);
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // code goes here
    int t=1;//cin>>t;
    while(t--){
      LLI x,y;cin>>x>>y;
      if((x+y)%3!=0){cout<<0;return 0;}
      if(2*x-y<0||2*y-x<0){cout<<0;return 0;}
      LLI i,m=(2*x-y)/3,n=(2*y-x)/3;
      fac[0]=1,fac[1]=1;
      fo(i,2,1e6+4){
        fac[i]=fac[i-1]*i%MOD;
      }
      cout<<(fac[m+n]*((modInverse(fac[m])*modInverse(fac[n]))%MOD))%MOD;
    }
    return 0;
}