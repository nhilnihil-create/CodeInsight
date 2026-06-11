#include<bits/stdc++.h>
#include<set>
#define lli long long int
using namespace std;
int main()
{
	lli t,a,n,i;
	cin>>n;
	vector<lli>v;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a=i+n/i-2;
			v.push_back(a);
		}
	}
	sort(v.begin(),v.end());
	cout<<v[0];	
	return 0;
}