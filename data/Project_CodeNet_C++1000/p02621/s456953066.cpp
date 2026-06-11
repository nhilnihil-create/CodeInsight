#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=3;i++)
	{
		sum+=pow(n,i);
	}
	cout<<sum;
	return 0;
}