    #include <bits/stdc++.h>
    #include <fstream>
    #include<string>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>


    typedef  long long ll;
    typedef long double ld;
    using namespace std;
    using namespace __gnu_pbds;


    #define endl "\n"
    #define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    const int N=3e5+5;
    ll mod=998244353 ;
    ll mul (ll a, ll b)
    {
        a%=mod;
        b%=mod;
        return (a*b)%mod;
    }
    ll add (ll a, ll b)
    {
        a%=mod;
        b%=mod;
        return (a+b+mod)%mod;
    }
    ll fastpow(ll b, ll p)
    {
        if(p==0)
            return 1;
        ll ans=fastpow(b,p/2);
        ans=mul(ans,ans);
        if(p%2)ans=mul(ans,b);
        return ans;
    }
    ll inf=1e18;
    const int M=(1<<13);
    ll dp[1005][M];
    int n,m;
    ll cost[1005];
    vector<int>v[N];
    bool checkall(int mask)
    {
        for(int i=0;i<n;i++)
        {
            if(((mask>>i)&1)==0)
                return 0;

        }
        return 1;


    }
    ll nower(int mask,int i)
    {

        for(auto j:v[i])
        {
            mask|=(1<<j);
        }
    return mask;

    }
    ll solve(int i, int mask)
    {
        if(i==m)
        {
            if(checkall(mask))
                return 0;
            else
                return inf;
        }
        ll &ans=dp[i][mask];
        if(ans!=-1)
            return ans;
        ans=1e18;
        ans=min(ans,solve(i+1,mask));

        ans=min(ans,solve(i+1,nower(mask,i))+cost[i]);
        return ans;


    }


    int main()
    {
        FIO
       memset(dp,-1,sizeof dp);
       cin>>n>>m;
       for(int i=0;i<m;i++)
       {
           int b;
           cin>>cost[i]>>b;
           while(b--)
           {
               int x;
               cin>>x;
               v[i].push_back(x-1);
           }
       }
       ll ans=solve(0,0);
       if(ans==inf)
        cout<<-1;
       else
        cout<<ans;

        return 0;
    }
