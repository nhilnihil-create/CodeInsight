#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int M=998244353;
const int inf=4e18;
const int N=2e5;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;cin>>n>>m;
	int a[n];
	unordered_set<int> s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]/=2;
		int p=a[i],cnt=0;
		while(p%2==0)
		{
			p/=2;
			cnt++;
		}
		s.emplace(cnt);
	}
	if(s.size()>1)
	{
		cout<<"0\n";
		return 0;
	}
	int LCM=1;
	for(int i=0;i<n;i++)
	{
		int g=__gcd(LCM,a[i]);
		LCM=(LCM*a[i])/g;
		if(LCM>m)
		{
			cout<<"0\n";
			return 0;
		}
	}
	int x=m/LCM;
	x-=(x%2==0);
	cout<<x/2+1<<'\n';
}