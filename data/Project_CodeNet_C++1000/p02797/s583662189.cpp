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

    int n,k,s;
    cin>>n>>k>>s;
    if(s==1e9)
    {
        for(int i=1;i<=k;i++)
            cout<<s<<" ";
        for(int i=k+1;i<=n;i++)
            cout<<1<<" ";
    }
    else
    {
        int z=1e9;
        for(int i=1;i<=k;i++)
            cout<<s<<" ";
        for(int i=k+1;i<=n;i++)
            cout<<z<<" ";
        
    }
    

} 

