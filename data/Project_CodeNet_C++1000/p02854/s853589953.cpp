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
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
int sum=0;
for(int i=0;i<n;i++)
    sum+=arr[i];
int c=0;

int ans=sum;
for(int i=0;i<n-1;i++)
{
    c+=arr[i];
    int l=sum-c;
    int mid=(l+c)/2;
    int res=abs(mid-c)+abs(mid-l);
    ans=min(ans,res);
}
cout<<ans<<endl;


















    return 0;
}
