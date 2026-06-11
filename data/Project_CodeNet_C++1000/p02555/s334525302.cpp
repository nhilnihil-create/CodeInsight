#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define ll long long int
#define vr vector
#define pb push_back
#define pf push_front
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define loop(i,n) for(i=0;i<n;i++)
#define inp !cin.eof()
#define sec itr->second
#define fir itr->first

ll power(ll x,ll y,ll p)
{
    ll res = 1;

    while (y > 0)
    {

        if (y & 1)
            res = (res*x)%p;


        y = y>>1;
        x = ((x%p)*(x%p))%p;
    }
    return res%p;
}



int main()
{
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     // iterating a loop until input is providing====!cin.eof()

  // ll t;cin>>t;

    // while(t--)
        {
            ll n,i,ans=0,x,a,b,k,cnt=0,sum=0,flag=0;
             vr<ll> v,v1;

            cin>>n;
            ll dp[20001];

            for(i=3;i<=2010;i++)
            {
                dp[i]=1;
            }
            dp[0]=0,dp[1]=0,dp[2]=0;

            for(i=4;i<=2010;i++)
            {
                sum=1;
                for(ll j=i-1;j>=3;j--)
                sum+=(dp[i-j])%mod;

                dp[i]=sum%mod;

            }


             cout<<dp[n];


         cout<<endl;

         }
    return 0;
}

