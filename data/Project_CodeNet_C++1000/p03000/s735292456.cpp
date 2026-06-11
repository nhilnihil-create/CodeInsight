#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ba=0,b1=1,x;
	cin>>n>>x;
	for(int t=0;t<n;t++)
	{
		int l; 
		cin>>l;
		ba+=l;
		if(ba<=x)
		{
			b1++; 
		}
	}
	cout<<b1;
	return 0;
} 