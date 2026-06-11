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
	int n,x;
	cin>>n>>x;
	vector<int> l(n);
	for(int i=0;i<n;i++)
	{
		cin>>l[i];
	}
	int ans=1;
	int bound=0;
	for(int i=0;i<n;i++)
	{
		bound+=l[i];
		if(bound<=x)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}