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
	int n;
	cin>>n;

	vector<int>a(n);

	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int cnt=0,k;


	sort(all(a));

	if(n<=2)
	{
		cout<<0<<endl;
		return;
	}

	for(i=0;i<n-2;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(a[i]+a[j]>a[k]&&(a[i]!=a[j]&&a[i]!=a[k]&a[j]!=a[k]))
				{
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl;

}
