#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,t;
	cin>>n>>a>>t;
	int l=n/a;
	if (n % a !=0)
	l=l+1;
	cout<<l*t;	
	return 0;
}