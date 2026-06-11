/* ****mittal**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define jell        998244353
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define DEC(N)  cout << std::fixed; cout << setprecision(N);
using namespace std;
ll add(ll x,ll y)
{
return (x%hell+y%hell)%hell;
}
ll mul(ll x,ll y)
{
return ((x%hell)*(y%hell))%hell;
}
ll sub(ll x,ll y)
{
return (x-y+hell)%hell;
}
#define N  100005
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
   //cin>>t;
    for(int ok=1;ok<=t;ok++)
    {
        
        ll n;
        cin>>n;
        ll a[n+3];
        for(int i=1;i<=n+1;i++)
        {
            cin>>a[i];
        }
        if(n==0&&a[1]==1)
        {
        	 cout<<1<<endl;
        	 return 0;
        }
        if(n==0)
        {
        	cout<<-1;
        	return 0;
        }
        if(a[1]==1&&n!=0)
        {
        	  cout<<-1;
        	  return 0;
        }
        if(a[n+1]==0)
        {
        	 cout<<-1<<endl;
        	 continue;
        }
        ll x=1;
        ll w=0;
        ll b[n+3];
        b[1]=1;
        ll io=1e15;
        for(int i=2;i<=n+1;i++)
        {
            if(a[i]>2*x)
            {
            	 w=1;
            	 break;
            }
            ll o=2*x-a[i];
            o=min(io,o);
            x=o;
            b[i]=o;
        }
        if(w)
        {
        	cout<<-1;
        	return 0;
        }
        ll ans[n+4];
        ans[n+1]=a[n+1];
        ans[1]=1;
        ll ox=a[n+1];
        ll op=ans[1]+ans[n+1];
        for(int i=n;i>=2;i--)
        {     if(2*b[i]<ox)
        	{
        		cout<<-1;
        		return 0;
        	}
              if(ox<b[i])
              	ox=a[i]+ox;
              else
              	ox=a[i]+b[i];
              ans[i]=ox;
              op+=ans[i];
        }
        cout<<op;

    }
    return 0;
}