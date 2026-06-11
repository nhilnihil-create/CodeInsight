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
	ll n;
	cin>>n;
	pair<int,int> p[n];
	int ave=1;
	for(int i=0;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		p[i].first=x;
		p[i].second=y;
		ave*=i+1;
	}
	vector<vector<double>> dist(n,vector<double>(n));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			double x_dis=pow((p[i].first-p[j].first),2);
			double y_dis=pow((p[i].second-p[j].second),2);
			double dis=x_dis+y_dis;
			dist[i][j]=sqrt(dis);
		}
	}
	vector<int> order(n);
	for(int i=0;i<n;++i)
	{
		order[i]=i;
	}
	double ans=0;
	do
	{
		double temp_dis=0;
		for(int i=1;i<n;++i)
		{
			temp_dis+=dist[order[i-1]][order[i]];
		}
		ans+=temp_dis;
	}while(next_permutation(order.begin(),order.end()));
	ans=ans/ave;
	printf("%10lf",ans);
	return 0;
}
