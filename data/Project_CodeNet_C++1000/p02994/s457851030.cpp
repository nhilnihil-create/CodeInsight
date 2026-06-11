#include "bits/stdc++.h"
using namespace std;
int n,l;
vector<int> v;
int main()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
		v.push_back(i+l-1);
	int sum=0;
	for(int i=0;i<n;i++)	
		sum+=v[i];
	int mn=1e9,ans;
	for(int i=0;i<n;i++)
		if(abs(sum-(sum-v[i]))<mn)
		{
			mn=abs(sum-(sum-v[i]));
			ans=sum-v[i];
		}
	cout<<ans<<endl;
	return 0;
}