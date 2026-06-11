#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#define LL long long
#define N 1000001
using namespace std;
const int NN=2e5+7;
LL x[NN],y[NN];
LL p[4][NN];
LL i,j,k;
LL pd;
int main()
{
	ios::sync_with_stdio(false);
  	LL n;
  	cin>>n;
  	for(i=1;i<=n;i++)
  	{
  		cin>>x[i]>>y[i];
  		p[0][i]=x[i]+y[i],p[1][i]=y[i]-x[i],p[2][i]=x[i]-y[i],p[3][i]=-(x[i]+y[i]);
	}
	for(i=0;i<=3;i++)
	sort(p[i]+1,p[i]+1+n);
	for(i=0;i<=3;i++)
	{
		pd=max(pd,p[i][n]-p[i][1]);
		//cout<<i<<"  "<<p[i][n]<<"  "<<p[i][1]<<endl;
	}
	cout<<pd;
	return 0;
}