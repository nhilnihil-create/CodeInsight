#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


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
    pair<int,int>p[n+1];
    int x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        p[i].first=x-y;
        p[i].second=x+y;     
    }
    sort(p+1,p+n+1);
    int ans=0;
    int prev=-1e10;
    for(int i=1;i<=n;i++)
    {
        if(prev<=p[i].first)
        {
            ans++;
            prev=p[i].second;
        }
        else
        {
            prev=min(prev,p[i].second);
        }        
    }
    cout<<ans;

} 

