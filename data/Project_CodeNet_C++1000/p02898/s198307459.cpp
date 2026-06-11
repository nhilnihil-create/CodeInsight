# include <iostream>
# include <algorithm>
using namespace std;
int main()
{
	int n,k,s;
	s=0;
	cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0; i<n; i++)
	{
		if(a[n-1-i]>=k)
		{
			s=s+1;
		}
		else
		{
			break;
		}
	}
	cout<<s;
}