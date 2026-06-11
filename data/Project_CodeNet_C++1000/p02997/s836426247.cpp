#include<bits/stdc++.h>
#define ll          long long int
#define lld          long double
#define pb          push_back
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define vec         vector<ll>
#define all(a)     (a).begin(),(a).end()
#define F           first
#define S           second
#define mod         1000000007
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repi(i,a,b)	for(ll  i=a;i<=b;i++)
#define per(i,a,b)  for(ll i=a;i>=b;i--)
#define mp          make_pair
#define mit         map<ll,ll>::iterator
#define sit         set<ll>::iterator
#define pit         pair<ll,ll>::iterator
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
ll xo(ll x, ll y) 
{ 
   return (x | y) & (~x | ~y); 
}  
ll bin_Expo(ll x,ll n)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return bin_Expo(x*x,n/2);
    else                             //n is odd
        return x*bin_Expo(x*x,(n-1)/2);
}
ll mod_Expo(ll x,ll n,ll M)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return mod_Expo((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*mod_Expo((x*x)%M,(n-1)/2,M))%M;

}
bool prime_check(ll x)
{
    bool prime = (x >= 2);
    for (ll i = 2; i * i <= x; i++) 
    {
        if (x % i == 0) 
        {
            prime = false;
            break;
        }
    }
    return prime;
}
ll logg(ll base,ll x) 
{
    return (ll)(log(x) / log(base));
}
ll lcm(ll x,ll y)
{
	return (x*y)/__gcd(x,y);
}
ll cc(ll a,ll b,ll c)
{
	return (b/c)-((a-1)/c);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
    while(TESTS--)
    {
    	ll j,l,m,h,w,f,n,k,b,t,i,ans,gap,limit,l1;
    	cin>>n>>k;
    	if(k<=((n-1)*(n-2))/2)
    	{
    		l=(((n-1)*(n-2))/2)-k;
    		ans=n-1+l;
    		cout<<ans<<'\n';
    		j=1;
    		rep(i,0,n-1)
    		cout<<n<<" "<<(j++)<<'\n';
    		gap=1; limit=n-2; j=2; l1=0;
    		while(l)
    		{
    			repi(i,1,n-2)
    			{
    				repi(j,i+1,n-1)
    				{
    					cout<<i<<" "<<j<<'\n';
    					l--;
    					if(l==0)
    					break;
					}
					if(l==0)
					break;
				}
			}
		}
		else
		cout<<-1;
    }
	return 0;
}