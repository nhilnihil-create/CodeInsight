#include<bits/stdc++.h>
using namespace std;

long long int n,i,x,a;
string s;
bool tr;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;n--;
	while (1==1)
	{
		n++;
		x=trunc(sqrt(n));tr=true;
		for (i=2;i<x+1;i++) if (n%i==0) tr=false;
		if (tr)
		{
			cout<<n;return 0;
		}
	}
}