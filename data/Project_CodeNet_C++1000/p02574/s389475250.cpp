#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define p 1437984
using namespace std;
int a[p],c[p];
inline void fj(int x);
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int maxxs=0;
	for(fint i=1;i<=n;i++)
	cin>>a[i],maxxs=max(a[i],maxxs);
	int now=a[1];
	for(fint i=2;i<=n;i++)
	now=__gcd(now,a[i]);
	bool s_c=0;
	if(now==1)
	s_c=1;
	for(fint i=1;i<=n;i++)
	fj(a[i]);
	bool p_c=1;
	for(fint i=1;i<=maxxs;i++)
	if(c[i]>1)
	p_c=0;
	if(p_c&&s_c)
	cout<<"pairwise coprime";
	else
	if(s_c&&!p_c)
	cout<<"setwise coprime";
	else
	cout<<"not coprime";
	return 0;
}

inline void fj(int x)
{
	int i=2;
	while(i*i<=x)
	{
		if(x%i==0)
		{
			c[i]++;
			while(x%i==0)
			x/=i;
		}
		i++;
	}
	if(x>1)
	c[x]++;
	return ;
}