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
	int w,h,x,y;
	int flag=0;
	cin>>w>>h>>x>>y;
	double ans=(double)w*h/2;
	if(x*2==w&&y*2==h)
	{
		flag=1;
	}
	printf("%.10f %d\n",ans,flag);
	return 0;
}



