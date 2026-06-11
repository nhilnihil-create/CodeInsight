#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<numeric>
#include<cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#define ll long long int
#define CON 100010
#define N 1500000
const long long mod=1e9+7;
const int INF=1001001001;
//const int inf=100000;
//const ll ful=1e18;
using namespace std;
//namespace mp = boost::multiprecision;
int main() 
{
	int n;
	cin>>n;
	vector<int> v(n);
	vector<int> p(n);
	vector<int> q(n);
	for(int i=0;i<n;++i)
	{
		cin>>p[i];
		v[i]=p[i];
	}
	for(int i=0;i<n;++i)
	{
		cin>>q[i];
	}
	sort(v.begin(),v.end());
	int a,b;
	int count=1;
	do
	{
		if(p==v)
		{
			a=count;
		}
		if(q==v)
		{
			b=count;
		}
		count++;
	}while(next_permutation(v.begin(),v.end()));
	int ans=abs(a-b);
	cout<<ans;
	return 0;
}