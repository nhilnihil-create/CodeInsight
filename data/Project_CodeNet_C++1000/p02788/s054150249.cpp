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
int n,d,a;
cin>>n>>d>>a;
pair<int,int> arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i].ff>>arr[i].ss;
}
sort(arr,arr+n);
int dp[n+1]={};
int inf=pow(10,15);
int ans=0;
for(int i=0;i<n;i++)
{if(i!=0)
    dp[i]+=dp[i-1];
    if(-1*dp[i]>=arr[i].ss)
    continue;
    int x=arr[i].ff;
    x=x+2*d;
    pair<int,int> r=make_pair(x,inf);
    int pos=upper_bound(arr,arr+n,r)-arr;
    int val=arr[i].ss+dp[i];
    int res=val/a;
   
    if(val%a!=0)
        res+=1; 
        ans+=res;
    dp[i]-=res*a;
    dp[pos]+=res*a;

}
cout<<ans<<endl;
    return 0;
}
