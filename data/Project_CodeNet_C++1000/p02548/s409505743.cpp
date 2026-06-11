#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long int count=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
			count+=(n/i-1);
		else
			count+=(n/i);
	}
	cout<<count<<endl;
	return 0;
}