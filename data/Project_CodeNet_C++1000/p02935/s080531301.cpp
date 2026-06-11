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
	vector<double> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n-1;i++)
	{
		v[i+1]=(v[i]+v[i+1])/2;
	}
	printf("%.10f",v[n-1]);
	return 0;
}