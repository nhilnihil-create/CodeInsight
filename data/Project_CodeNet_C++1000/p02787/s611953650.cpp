                                      // Believe in yourself
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Pair vector<pair<ll,ll>>
#define vec vector <ll> 
#define all(a) a.begin(),a.end()
#define mo 1000000007
#define decimal(i,n) fixed << setprecision(i) << n
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define show_nl(a) for(auto xyz:a)cout<<xyz<<endl;


void eea(ll a,ll b,ll &x,ll &y)
{
    if (a == 1)
    {
        x = 1; y = 0;
        return;
    }
    ll x1, y1;
    eea(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
}
ll mi(ll a,ll m)
{
    ll x,y;
    eea(a,m,x,y);
    x= (x%m+m)%m;
    return x;
}

/*
Enter the test case


Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
*/


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll h,n;
        cin>>h>>n;
        ll a,b,p=1,q=1;
        vector <pair <ll,ll>> v;
        cin>>p>>q;
        v.PB(MP(p,q));
        for(ll i=1;i<n;i++)
        {
            cin>>a>>b;
            v.PB(MP(a,b));
            if(p<a)
            {
            p=a;
            q=b;
            }
        }
        sort(all(v));
        ll dp[h+p+5];
        for(int i=0;i<=h+p+1;i++)
        dp[i]=1000000000;
        for(ll i=1;i<=h+p+1;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(i-v[j].F<=0)
                {
                    dp[i]=min(dp[i],v[j].S);
                }
                else
                {
                    dp[i]=min(dp[i],dp[i-v[j].F]+v[j].S);
                }
            }
        }
        ll ans=dp[h];
        for(ll i=h;i<=h+p;i++)
        {
            ans=min(ans,dp[i]);
        }
        cout<<ans<<"\n";
    }
}

