#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int i,n,x,y;
	cin>>n;
	vector<long long int>a(n),b(n);
	
	
	for(i=0;i<n;i++)
		{
			cin>>x>>y;
			a[i]=x+y;
			b[i]=x-y;
			
		}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	cout<<max((a[n-1]-a[0]),(b[n-1]-b[0]))<<endl;
}