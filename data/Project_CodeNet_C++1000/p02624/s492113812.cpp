#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>
//#include <boost/multiprecision/cpp_int.hpp>

//namespace mp = boost::multiprecision;
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
//using Bint = mp::cpp_int;

ll N;
ll num4dev(ll n)
{
	ll y=N/n;
	return y*(y+1)*n/2;
}


int main()
{
	cin>>N;
	ll res=0;
	for(ll i=1;i<=N;i++)
	{
		res+=num4dev(i);
	}
	cout<<res<<endl;
}