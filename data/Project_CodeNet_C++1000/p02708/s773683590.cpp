#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;
int arr[n+1];
for(int i=0;i<=n;i++)
    arr[i]=i;
int pref[n+1]={};
for(int i=1;i<=n;i++)
    pref[i]+=arr[i]+pref[i-1];
int suff[n+1]={};
suff[n]=arr[n];
for(int i=n-1;i>=0;i--)
    suff[i]+=suff[i+1]+arr[i];
    int mod=pow(10,9)+7;
    int ans=0;
for(int i=k-1;i<=n;i++)
{
    ans+=suff[n-i]-pref[i]+1;
    ans%=mod;
    ////cout<<ans<<" ";
}
cout<<ans<<endl;
    return 0;
}
