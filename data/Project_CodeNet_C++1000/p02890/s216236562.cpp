#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int ans[300005];
int mm[300005];
vector<int>v[300005];
int res[300005];

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
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mm[a[i]]++;
    }

    int tot=0;
    for(int i=1;i<=n;i++)
    {
        v[mm[i]].push_back(i);
        tot+=mm[i];
    }

    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        for(auto j:v[i])
        {
            tot-=i;
            cnt++;
        }
        int z=tot+cnt*i;
        z/=i;
        res[z]=max(res[z],i);
    }
    for(int i=n;i>=1;i--)
    {
        res[i]=max(res[i],res[i+1]);
    }

    for(int i=1;i<=n;i++)
        cout<<res[i]<<'\n';


} 

