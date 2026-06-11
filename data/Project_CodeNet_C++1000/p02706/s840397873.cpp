#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a,s=0;
	cin>>n>>m;
	while(m--)
	{
		cin>>a;
		s=s+a;
	}
	if(s>n)
	cout<<"-1";
	else
	cout<<(n-s);
	return 0;
}