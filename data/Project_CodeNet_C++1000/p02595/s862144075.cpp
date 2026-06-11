#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
	ll n,d,i,j,x,y,ans=0;
	cin >> n >> d;
	
	for(i=0;i<n;i++)
	{
		cin >> x >> y;
		j = ceil(sqrt((x*x)+(y*y)));
		if(j<=d)  ans++;
	}
	
	cout << ans;
}

