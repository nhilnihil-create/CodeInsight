#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<numeric>
#include<cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#define ll long long int
#define CON 100010
//#define N 1500000
//const long long mod=1e9+7;
//const int INF=1001001001;
//const int inf=100000;
//const ll ful=1e18;
const double PI=3.1415926535897932;
using namespace std;
//namespace mp = boost::multiprecision;
int main() 
{
	double a,b,h,m;
	cin>>a>>b>>h>>m;
	double sho=h*30+m/2;
	double lar=m*6;
	double rad=abs(sho-lar);
	double num=pow(a,2)+pow(b,2)-2*a*b*cos(PI*rad/180);
	double ans=sqrt(num);
	printf("%17.13f",ans);
	return 0;
}