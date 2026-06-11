#include<bits/stdc++.h>
using namespace std;

int a[200001],b[200001];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	long long ans;
	if(n%2==0)
		ans=b[n/2]+b[(n/2)+1]-a[n/2]-a[(n/2)+1]+1;
	else
		ans=b[(n+1)/2]-a[(n+1)/2]+1;
	
	cout<<ans<<endl;
	return 0;
}