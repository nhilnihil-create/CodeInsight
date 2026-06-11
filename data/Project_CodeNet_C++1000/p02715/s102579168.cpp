#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const int mod=1e9+7;
ll f[maxn],n,k,ans;
ll fast(ll m,ll c){
    ll a=1;
    while(c)
	{
        if(c%2==1) a=a*m%mod;
        m=m*m%mod;
        c=c/2;
    }
    return a;
}
int main(){
    cin>>n>>k;
    for(int i=k;i>=1;i--)
	{
        f[i]=fast(k/i,n);
        for(int j=i*2;j<=k;j+=i)
            f[i]=(f[i]-f[j]+mod)%mod;
        ans=(ans+f[i]*i)%mod;
    }
    cout<<ans;
    return 0;
}