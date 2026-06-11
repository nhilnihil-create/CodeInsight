#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	int i,j,k;int sum=0;
	for(i=1;i<n;i++)
	{
		for(j=1;;j++)
		{
			if(i*j<n)
			sum++;
			else
			break;
		}
	}
	cout<<sum<<endl;
	return 0;
}