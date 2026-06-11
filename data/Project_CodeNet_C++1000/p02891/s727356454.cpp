# include <iostream>
# include <string>
# include <vector>
using namespace std;
int main()
{
	long long p,q,m,l,a,j,w,n;
	string s;
	cin>>s;
	cin>>w;
	s=s+s[0];
	n=s.size();
	p=0;
	m=0;
	l=0;
	a=0;
	j=0;
	vector<int>x;
	if(n==2)
	{
		cout<<w/2;
		return 0;
	}
	for(int i=0; i<n-1; i++)
	{
		if(s[i]==s[i+1])
		{
			p=p+1;
			q=1;
			if(i==n-2 && x.size()!=0)
			{
				a=p;
				if(a%2==0 || x[0]%2==0)
				{
					m=m+a/2*w;
				}
				else
				{
					m=m+(a/2+1)*w-1;
				}
			}
			if(i==n-2 && x.size()==0)
			{
				a=p;
				if(a%2==0)
				{
					m=m+a/2*w;
				}
				else
				{
					if(w%2==0)
					{
						m=m+a/2*w/2;
						m=m+(a/2+1)*w/2;
					}
					else
					{
						m=m+a/2*(w/2+1);
						m=m+(a/2+1)*(w/2);
					}
				}
			}
		}
		else
		{
			if(q==1)
			{
				m=m+(p+1)/2*w;
				x.push_back(p+1);
				p=0;
				q=0;
			}
		}
	}
	cout<<m;
}