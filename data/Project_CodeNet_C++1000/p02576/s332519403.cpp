#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,t;
	cin>>n>>x>>t;
	int a=(n+x-1)/x;
	cout<<a*t;
	return 0;
}