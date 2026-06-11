#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
#define MP make_pair
#define PB push_back
#define ll long long
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)
#define ld long double
#define mod 1000000007


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int an=0;
	f(i,1,n+1)
	{
		an=an^i;
	}
	if(an==0)
	{
		cout<<"Yes\n";
		f(i,1,2*n)
		{
			cout<<i<<" "<<i+1<<'\n';
		}
	}
	else if(n<3)
		cout<<"No\n";
	else if(n>4&&  (n%2==1)  )
	{
		cout<<"Yes\n";
		for(int i=2;i<=n-3;i++)
			cout<<i<<" "<<i+1<<'\n';
		cout<<n-2<<" "<<n+1<<'\n';
		for(int i=1;i<=n-3;i++)
			cout<<i+n<<" "<<i+1+n<<'\n';
		cout<<2*n<<" "<<2*n-1<<'\n';
		cout<<2*n-1<<" 1\n";
		cout<<"1 "<<n<<'\n';
		cout<<n<<" "<<n-1<<'\n';
		cout<<n-1<<" "<<n+1<<'\n';
	}
	else if( (an^(n+1))==0 )
	{
		cout<<"Yes\n";
		for(int i=3;i<n-3;i++)
			cout<<i<<" "<<i+1<<'\n';
		cout<<n-3<<" "<<n+1<<'\n';
		for(int i=1;i<n-3;i++)
			cout<<i+n<<" "<<i+1+n<<'\n';
		cout<<n+1<<" "<<n-1<<'\n';
		cout<<n-1<<" "<<n<<'\n';
		cout<<n<<" 2\n";
		cout<<"2 1\n";
		cout<<"1 "<<2*n-1<<'\n';
		cout<<2*n-1<<" "<<2*n<<'\n';
		cout<<n-2<<" 1\n";
		cout<<2*n-2<<" "<<2*n-1<<'\n';
	}
	else
	{
		if(an==n)
		{
			an=an^(n-1);
			f(i,1,n+1)
			{
				an^=i;
				if(an==0)
				{
					cout<<"Yes\n";
					f(i,1,n-1)
						cout<<i<<" "<<i+1<<'\n';
					cout<<n-1<<" "<<n+1<<"\n";
					f(i,n+1,2*n-1)
						cout<<i<<" "<<i+1<<'\n';
					cout<<n-1<<" "<<n<<'\n';
					cout<<i+n<<" "<<2*n<<'\n';
					return 0;
				}
			}
		}
		cout<<"No\n";
	}
	return 0;
}