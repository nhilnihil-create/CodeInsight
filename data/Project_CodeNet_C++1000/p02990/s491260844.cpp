
#include<bits/stdc++.h>
using namespace std;
#define point complex<double>
const long long N = 3e3+5,mod=1e9+7;
typedef long long ll;
ll fact[N],inv[N];
ll fp(ll num,ll p){
if(p==0)return 1;
ll ans=fp(num,p/2);
ans=(ans*ans)%mod;
if(p%2!=0)
    ans=(ans*(num%mod))%mod;
return ans;
}
ll ncr(int n ,int m){
return (((fact[n]*inv[m])%mod)*inv[n-m])%mod;
}
int main(){
fact[0]=inv[0]=1;
for(int i=1;i<=3000;i++){
    fact[i]=(i*fact[i-1])%mod;
    inv[i]=fp(fact[i],mod-2);
}
 ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
int n,k;
cin>>n>>k;
int r=n-k,b=k;
for(int i=1;i<=k;i++){
    if(r+1-i<0){cout<<0<<'\n';continue;}

    cout<<(ncr(b-1,i-1)*ncr(r+1,i))%mod<<'\n';
}
   return 0;
}
