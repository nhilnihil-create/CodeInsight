#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,ans=0;
	cin>>n;
	int x=n/500;
	ans+=x*1000;
	n-=x*500;
	ans+=n/5*5;
	cout<<ans; 
	return 0;
}