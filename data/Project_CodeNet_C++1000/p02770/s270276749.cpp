#include<iostream>
using namespace std;
int main()
{
	int k,q,i,d1[5005],d,n,x,m;
	long long sum;
	cin>>k>>q;
	for(int i=0;i<k;i++)
	cin>>d1[i];
	while(q--)
	{
		sum=0;
		cin>>n>>x>>m;
		n--;
		for(i=0;i<k;i++)
		{
			d=d1[i]%m;
			if(d==0) d=m;
			sum+=d;
		}
		sum=sum*(n/k);sum=sum+x%m;
		for(i=0;i<(n%k);i++)
		{
			d=d1[i]%m;
			if(d==0) d=m;
			sum+=d;
		}
		cout<<n-sum/m<<endl;
	}
	return 0;
}