#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,a[101],s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i%2!=0&&a[i]%2!=0)
		s++;
	}
	cout<<s;
	return 0;
}