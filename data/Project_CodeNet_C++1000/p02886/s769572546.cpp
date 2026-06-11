#include <bits/stdc++.h>
using namespace std;
void nil()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int m= a[i]*a[j];
			sum=sum+m;
			//cout<<m<<endl;
		}
	}
	cout<<sum<<endl;
	
}
int main()
{
	#ifndef ONLINE_JUDGE

		freopen("input1.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif	
		nil();

}