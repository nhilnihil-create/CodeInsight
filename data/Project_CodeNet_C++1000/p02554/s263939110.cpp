#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long fastexpo(long long a,long long n,int p) {
    if(n==0)
    return 1LL%p;
    long long u=fastexpo(a,n/2,p);
    u=(u*u)%p;
    if(n%2==1)
    u=(u*a)%p;
    return u;
}

int main() {
    long long n;
    cin>>n;
    if(n==1) {
        cout<<0;
        return 0;
    }
    
    long long ans1=fastexpo(9LL,n,mod);
    ans1=(ans1*2LL)%mod;
    long long ans2=fastexpo(8LL,n,mod);
    ans2%=mod;
    long long ans=fastexpo(10LL,n,mod);
    ans%=mod;
    ans=ans-ans1+ans2;
    ans%=mod;
    if(ans<0)
    ans+=mod;
    ans%=mod;
    cout<<ans;
}
