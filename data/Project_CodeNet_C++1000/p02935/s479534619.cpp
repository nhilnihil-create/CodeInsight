#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int main()
{
	long long int i,n;
	double ans;
	cin>>n;
	int v[n];
	for(i=0;i<n;i++)
		cin>>v[i];
	sort(v,v+n);
	ans=(double)(v[0]+v[1])/2;
	for(i=2;i<n;i++)
	{
		ans=(double)(ans+v[i])/2;
	}
	 cout << fixed << setprecision(5) << ans <<endl;
}