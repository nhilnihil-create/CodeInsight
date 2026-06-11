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
	int x;
	cin>>x;
	int lim=1500000;
	bool flag;
	for(int i=x;i<N;++i)
	{
		flag=true;
		for(int j=2;j*j<i;++j)
		{
			if(i%j==0)
			{
				flag=false;
			}
		}
		if(flag)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}