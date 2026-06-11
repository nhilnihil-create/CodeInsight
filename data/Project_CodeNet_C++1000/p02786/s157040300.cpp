#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,x=1,i;
	cin>>n;
	for(i=2;;i=i*2)
	{
		if(n!=1)
		{
		n=n/2;
		x=x+i;
		}
		else
		{
			break;
		}
	}	
	cout<<x<<endl;
}
