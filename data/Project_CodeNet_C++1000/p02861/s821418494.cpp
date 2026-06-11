#include<bits/stdc++.h>
using namespace std;
int n,x[10],y[10];
int main()
{
	cin >> n;
	double k=1;
	for(int i=1; i<=n; i++) cin >> x[i] >> y[i];
	double ans=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			ans+=(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
	printf("%.10lf",ans/n);
	return 0;
}