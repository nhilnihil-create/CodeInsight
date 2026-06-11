#if __has_include("debug.h")
    #include "debug.h"
#else  
#include <bits/stdc++.h>
using namespace std;
#define d(...) 2;
#endif

#define int long long int

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"      

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ff first
#define ss second
#define eps 1e-10

#define gcd(a,b)            __gcd((a),(b))
#define lcm(a,b)            ((a*b)/gcd(a,b))

void solve();
const int N=5e5;
int hh[N],ww[N];

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
	int h,w,n;
	cin>>h>>w>>n;

	int x=n;

	int a[n],b[n];

	int hmax=0,wmax=0;

	set<pair<int, int>>s;

	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		hmax=max(hmax,++hh[a[i]]);
		wmax=max(wmax,++ww[b[i]]);
		s.insert({a[i],b[i]});
	}

	int i1=0,i2=0;
	vector<int>hms,wms;

	for(i=1;i<=h;i++)
	{
		if(hh[i]==hmax)
		{
			hms.push_back(i);
		}
	}

	for(i=1;i<=w;i++)
	{
		if(ww[i]==wmax)
		{
			wms.push_back(i);
		}
	}

	d(hms,wms,s);

	for(i=0;i<hms.size();i++)
	{
		for(j=0;j<wms.size();j++)
		{

			if(!s.count({hms[i],wms[j]}))
			{
				cout<<hmax+wmax<<endl;
				return;
			}
		}
	}

	cout<<hmax+wmax-1<<endl;




}