#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[200000],N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}
	sort(a,a+N);
	for(int i=0;i<N;i++)
	{
		if(a[i]==a[i+1])
		{
		cout<<"NO"<<'\n';
		return 0;
		}
	}
	cout<<"YES"<<'\n';
	return 0;
} 
