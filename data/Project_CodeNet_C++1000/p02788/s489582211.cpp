#if __has_include("debug.h")
    #include "debug.h"
#else  
#include <bits/stdc++.h>
using namespace std;
#define d(...) 2;
#endif

#define int long long int
#define ld long double

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"      

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ff first
#define ss second
#define eps 1e-10
#define PI acos(-1LL)

#define gcd(a,b)            __gcd((a),(b))
#define lcm(a,b)            ((a*b)/gcd(a,b))

void solve();

int32_t main()
{
    #ifdef DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif 

    fast
    
    int t = 1;
	// cin>>t;
	
	while(t--)
	    solve();
	return 0;  
}

void solve()
{
	int i,j;
	
	int n,d,a;
	cin>>n>>d>>a;

	vector<pair<int, int>>xh(n);

	for(i=0;i<n;i++)
	{
		cin>>xh[i].ff>>xh[i].ss;
	}

	sort(all(xh));

	vector<int>needed(n);

	for(i=0;i<n;i++)
	{
		needed[i]=ceil(xh[i].ss/(ld)a);
	}

	d(needed);

	vector<int>last(n,0);
	int ans=0;

	j=1;

	for(i=0;i<n;i++)
	{
		while(j<n&&xh[j].ff-xh[i].ff<=2*d)
		{
			j++;
		}
		int cnt=max(0LL,needed[i]-last[i]);
		d(i,j,cnt,last);
		ans+=cnt;
		last[i]+=cnt;

		if(i==n-1)
		{
			break;
		}

		last[j]-=cnt;

		last[i+1]+=last[i];

	}
	cout<<ans<<endl;

}