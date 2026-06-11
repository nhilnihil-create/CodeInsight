#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mx[100005];
int tot[100005];

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

    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    mx[0]=1-a[0];
    if(mx[0]<0)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int z=mx[i-1]*2-a[i];
        int mm=1e15;
        z=min(z,mm);
        if(z<0)
        {
            cout<<-1;
            return 0;
        }
        mx[i]=z;
    }
    tot[n]=a[n];
    for(int i=n-1;i>=0;i--)
    {
        int z=tot[i+1];
        tot[i]=a[i]+min(mx[i],tot[i+1]);
    }
    for(int i=1;i<=n;i++)
    {
        int z=tot[i-1]-a[i-1];
        z*=2;
        if(tot[i]>z)
        {
            cout<<-1;
            return 0;
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        ans+=tot[i];
    }
    
    cout<<ans;

} 

