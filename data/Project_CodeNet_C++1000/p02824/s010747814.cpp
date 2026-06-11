
#include<bits/stdc++.h>
using namespace std;

// data types
#define ll long long int
#define ld long double

//funtion macros


// stl
#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define ilp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define sz(x) ((ll)((x).size()))

#define mod 1000000007

// utility functions
ll max(ll a, ll b)
{
    if(a>b)return a;
    return b;
}

ll min(ll a, ll b)
{
	if(a<b)return a;
    return b;
}

ll power(ll x, ll y, ll m=mod)
{
	if(y<0)
    {
		x = power(x,m-2);
		y = -y;
	}
	ll ans=1;
	x = x % m;
	while(y)
    {
		if(y&1) ans = (ans*x)%m;
		y=y/2;
		x=(x*x)%m;
	}
	return ans;
}

bool poss(ll c, ll arr[],ll pos,ll v, ll m, ll n, ll p)
{
    if(pos>(arr[n-c]+m))
    {
        return 0;
    }
    else if(pos==arr[n-c])
    {
        return 1;
    }
    else
    {
        ll cnt = 0;
        cnt = (p-1)*m;
        lp(i,0,n-p+1)
        {
            cnt += min((arr[n-c]+m-arr[i]),m);
        }
        if(cnt>=v*m)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,m,v,p,i;
    cin >> n >> m >> v >> p;
    ll arr[n];
    lp(i,0,n)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    ll pos = arr[n-p];
    ll min = p, max = n,avg,res=p;
    while(min<=max)
    {
        avg = min + (max-min)/2;
        if(poss(avg,arr,pos,v,m,n,p))
        {
            res = avg;
            min = avg+1;
        }
        else
        {
            max = avg-1;
        }        
    }
    cout << res << "\n";
	return 0;
}