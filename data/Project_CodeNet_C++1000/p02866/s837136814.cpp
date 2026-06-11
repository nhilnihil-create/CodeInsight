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
int n;
cin>>n;
int ans=1;
map<int,int> mp;
int arr[n+1];
int mod=998244353;
for(int i=1;i<=n;i++)
{
    cin>>arr[i];
}
if(arr[1]!=0)
{//cout<<"yes"<<endl;
    cout<<0<<endl;
    return 0;
}
arr[0]=0;
sort(arr,arr+n+1);
mp[0]=1;
for(int i=2;i<=n;i++)
{
    ans*=mp[arr[i]-1];
    ans%=mod;
    mp[arr[i]]++;
}
cout<<ans<<endl;
















    return 0;
}
