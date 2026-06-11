# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;
int main()
{
	long long n,l,s,p;
	cin>>n;
	int a[n];
	l=0;
	s=0;
	int b[1000000]={0};
	int c[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	sort(a,a+n);
	p=a[0];
	for(int i=0; i<n; i++)
	{
		if(p==a[i])
		{
			l=l+1;
		}
		else
		{
			b[p]=l;
			p=a[i];
			if(l>=2)
			{
				s=s+l*(l-1)/2;
			}
			l=1;
		}
	}
	b[p]=l;
	if(l>=2)
	{
		s=s+l*(l-1)/2;
	}
	for(int i=0; i<n; i++)
	{
		cout<<(s-b[c[i]]+1)<<endl;
	}
}