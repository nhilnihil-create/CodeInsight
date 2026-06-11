#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define rap(p,a,b) for(ll p=a ; p<=b ; p++)
#define per(p,a,b) for(ll p=a ; p>=b ; p--)
#define F first
#define S second
using namespace std;

typedef vector <ll> vll;
typedef vector <ld> vld;
typedef pair< ll ,ll > pll;

vll a(10004),b(10004),dp(10004,1e8+7);
ll n,ma=1e9;


int main()
{
    ll t,i,j,k,ans,h;

    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>h>>n;
        rep(p,0,n)cin>>a[p]>>b[p];

        dp[0] = 0;
        rep(p,1,h+1)
        {
            rep(q,0,n)
            {
                ll tmp = p-a[q];
                if(tmp<0)tmp=0;
                dp[p] = min(dp[p],dp[tmp]+b[q]);
            }
        }

        cout<<dp[h];
    }
    
    return 0;
}