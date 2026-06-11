#include<bits/stdc++.h>
#include<numeric>
#include<cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#define ll long long int
#define CON 100010
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
	vector<int> a(n);
	map<int,int> p{};
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		p[a[i]-1]=i+1;
	}
	for(int i=0;i<n;++i)
	{
		cout<<p[i]<<" ";
	}
	return 0;
}