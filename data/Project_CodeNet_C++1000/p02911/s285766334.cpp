#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,q;
	cin>>n>>k>>q;
	int i,j,b[n];
	
	fill_n(b,n,k-q);
	for(i=0;i<q;i++)
	{ 
	int a;
		cin>>a;
		b[a-1]++;
	}
	
	for(i=0;i<n;i++)
	{
		if(b[i]<=0)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}

}