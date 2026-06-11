#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long po(long long p,long long n){
    long long x=1;
    for(int i=n;i>0;i/=2){
        if(i%2){
            x*=p;
            x%=mod;
        }
        p*=p;
        p%=mod;
    }
    return x;
}
int main(){
    long long n,k,x=0;
    cin>>n>>k;
    long long g[k+1];
    for(int i=k;i>0;i--){
        g[i]=po(k/i,n);
        for(int j=i*2;j<=k;j+=i)g[i]-=g[j];
        g[i]=(g[i]%mod+mod)%mod;
        x+=g[i]*i;
        x%=mod;
    }
    cout<<x<<endl;
    return 0;
}