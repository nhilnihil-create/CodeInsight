#include <bits/stdc++.h>
typedef long long ll;

#define pll pair<ll,ll>
#define ff first
#define snd second
#define pb push_back
#define vll vector<ll>
#define vpll vector<pll>
#define endl "\n"
#define MOD 1000000007
using namespace std;

ll const N = 1e5+1;

int f(ll x,ll y)
{
        while((x%y)==0)
        {
                x/=y;
        }
        return ((x%y)==1);
}

void solve()
{
   ll n;
   cin>>n;
   ll ans = 0;
   
   if(n==2)
   {
           cout<<1;
           return;
   }
   
   for(ll i=1;i*i<=n;i++)
   {
           if(i==1)
           {
                ans++;
                continue;
           }
           if(n%i==0)
           {
                   if(i*i==n)
                   {
                        ans+=f(n,i);   
                   }
                   else
                   {
                           ans+=f(n,i);
                           ans+=f(n,n/i);
                   }
           }
   }
   n--;
   for(ll i=1;i*i<=n;i++)
   {
           if(i==1)
           {
                   ans++;
                   continue;
           }
           if(n%i==0)
           {
                   if(i*i==n)
                   {
                        ans++;   
                   }
                   else
                   {
                           ans+=2;
                   }
           }
   }
   
   cout<<ans;
}
 
int main() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    int t=1;
	    //cin>>t;
	    while(t--)
	    {
	            solve();
	    }
	    return 0;
}