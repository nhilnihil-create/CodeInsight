#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod=1e9+7;
int dp[200005][2];
int mm[200005];


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
    n*=2;
    string s;
    cin>>s;
    s="#"+s;
    dp[0][0]=1;
    if(s[1]=='W')
    {
        cout<<0;
        return 0;
    }
    vector<int>pos;
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]=='W')
        {
            dp[i][1]=dp[i-1][0];
            dp[i][0]=dp[i-1][1];
            if(dp[i][1])
                mm[i]=1;
        }
        else
        {
            dp[i][0]=dp[i-1][1];
            dp[i][1]=dp[i-1][0];
            if(dp[i][0])
                mm[i]=1;
        }        
    }
    int ans=1;
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        if(mm[i])
        {
            ans*=tot;
            tot--;
        }
        else
        {
            tot++;
        }        
        if(tot<0)
        {
            cout<<0;
            return 0;
        }
        ans%=mod;
    }
    if(tot!=0)
    {
        cout<<0;
        return 0;
    }
    int lol=1;
    for(int i=1;i<=n/2;i++)
    {
        lol*=i;
        lol%=mod;
    }
    ans*=lol;
    ans%=mod;
    cout<<ans;

} 

