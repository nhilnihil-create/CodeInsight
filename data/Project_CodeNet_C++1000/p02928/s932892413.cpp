#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mm[2005];
const int mod=1e9+7;

signed main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++)  
    {
        cin>>a[i];
        mm[a[i]]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i]-1;j>=1;j--)
        {
            ans+=(mm[j]*((((k-1)*(k))/2)%mod))%mod;
            ans%=mod;
        }
        int tt=0;
        for(int j=n;j>i;j--)
        {
            if(a[j]<a[i])
            {
                tt++;
            }
        }
        ans+=(tt*k)%mod;
        ans%=mod;
    }
    cout<<ans;


} 

