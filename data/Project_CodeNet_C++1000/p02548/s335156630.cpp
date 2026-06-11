#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
			count+=n/i-1;
		else
			count+=n/i;
	}
	cout<<count;
	return 0;
}