#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int M=1e5+5;
const ll mod=998244353;
ll ct[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int mx=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int d;
		cin>>d;
		if(i==1 && d)
		{
			cout<<"0\n";
			return 0;
		}
		if(i>1 && d==0)
		{
			cout<<"0\n";
			return 0;
		}
		ct[d]++;
		mx=max(mx,d);
	}
	ll res=1;
	for(ll i=1;i<=mx;i++)
	{
		if(ct[i]==0)
			res=0;
		for(int j=0;j<ct[i];j++)
			res=(res*ct[i-1])%mod;
	}
	cout<<res<<"\n";
	return 0;
}
