#include<bits/stdc++.h>
using namespace std;
bool prime(int x)
{
	bool f=true;
	if(x==1)
		f=false;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			f=false;
			break;
		}
	}
	return f;
}
int n;
int main()
{
	cin>>n;
	while(!prime(n))
		n++;
	cout<<n;
}