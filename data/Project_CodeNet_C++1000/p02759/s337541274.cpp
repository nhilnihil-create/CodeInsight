#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,b;
	cin>>n;
	b=n/2;
	if(n&1)
	cout<<b+1;
	else
	cout<<b;
	return 0;
}