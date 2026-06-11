#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n,k;
int store[100005];
int mod=1e9+7;
int power(int x,int y,int p)
{ 
    int res = 1;      
    x = x % p;  
    while (y > 0) 
    { 
        if((y & 1)==1) 
            res = (res * x) % p; 
        y = y >> 1;  
        x = (x * x) % p;  
    } 
    return res; 
} 

int32_t main() 
{
    IOS;
    cin>>n>>k;
    for(int i=k;i>=1;i--)
    {
        int ans=power(k/i,n,mod);
        for(int j=2;i*j<=k;j++)
            ans=(ans-store[i*j]+mod)%mod;
        store[i]=ans;
    } 
    int sum=0;
    for(int i=1;i<=k;i++)
        sum=(sum+(i*store[i])%mod)%mod;
    print(sum);
}   
