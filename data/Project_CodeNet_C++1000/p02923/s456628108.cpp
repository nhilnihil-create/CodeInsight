#include<bits/stdc++.h>
#include<numeric>
#include<cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#define ll long long int
#define CON 100010
const long long mod=1e9+7;
const int INF=1001001001;
const int inf=100000;
//const ll inf=1e9+7;
//const ll ful=1e18;
using namespace std;
//namespace mp = boost::multiprecision;
int main() 
{
	int n;
	cin>>n;
	vector<int> h(n);
	for(int i=0;i<n;++i)
	{
		cin>>h[i];
	}
	int ans=0;
	int now=0;
	for(int i=0;i<n-1;++i)
	{
		now=0;
		for(int j=i;j<n-1;++j)
		{
			if(h[j]>=h[j+1])
			{
				now++;
				if(now>ans)
				{
					ans=now;
				}
				continue;
			}
			break;
		}
		if(ans>=n-i) break;
	}
	cout<<ans<<endl;
	return 0;
}