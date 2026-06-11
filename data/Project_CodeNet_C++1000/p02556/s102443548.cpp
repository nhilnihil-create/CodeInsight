#include<bits/stdc++.h>
using namespace std;
int a[2000001],b[2000001];
int main()
{
	int n;
	cin>>n;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[i]=x+y;
		b[i]=x-y;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	cout<<max(abs(a[1]-a[n]),abs(b[1]-b[n]))<<endl;
	return 0;
}