#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,a,b;
	cin>>n>>k;
	a=n%k;
	b=abs(a-k);
	if(a>b)
	{
		cout<<b<<endl;
	}
	else
	{
		cout<<a<<endl;
	}
}