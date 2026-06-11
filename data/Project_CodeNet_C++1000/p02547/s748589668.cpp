#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,k;
	cin>>n;
	int a[n],b[n];
	for(i=0;i<n;i++)
	cin>>a[i]>>b[i];
	for(i=0;i<n-2;i++)
		if(a[i]==b[i] && a[i+1]==b[i+1] && a[i+2]==b[i+2])
		{
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}