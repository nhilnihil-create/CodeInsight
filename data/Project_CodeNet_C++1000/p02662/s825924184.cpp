#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double
 
int mod = 998244353;
int n,s;
int arr[3005];
int cache[3005][3005];
int power[3005];
 
int dp(int pos,int sum)
{
    if(sum==s)
        return power[n-pos];
 
    if(pos==n || sum>s)
        return 0;
 
    int &ans=cache[pos][sum];
    if(ans!=-1)
        return ans;
 
    ans=2*dp(pos+1,sum)+dp(pos+1,sum+arr[pos]);
    ans%=mod;
    return ans;
}
int32_t main() 
{
    IOS;
    power[0]=1;
    for(int i=1;i<=3002;i++)
        power[i]=(2*power[i-1])%mod;
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(cache,-1,sizeof(cache));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a=(power[i]*dp(i+1,arr[i]))%mod;
        ans=(ans+a)%mod;
    }
    print(ans);
}   