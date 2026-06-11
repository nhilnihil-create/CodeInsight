#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef string str;

int main ()
{
	// ios::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);
	ll t,n,m,k,i,a,b,j;
	cin >> n;
	ll arr[n+2];
	for(i=0;i<=n;i++)
	{
		cin >> arr[i];
	}
	b=0;
	ll node[n+2],atnode[n+2];
	node[n]=arr[n];
	atnode[n]=arr[n];
	for(i=n-1;i>=0;i--)
	{
		a=node[i+1]/2 + node[i+1]%2 + arr[i];
		if(i<60 && pow(2,i)<a)
		{
			b=1;
			break;
		}
		else
		{
			node[i]=a;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		atnode[i]=atnode[i+1]+arr[i];
		if(i<60 && atnode[i]>pow(2,i))
			atnode[i]=pow(2,i);
	}
	if(!b)
	{
		node[0]=1;
		k=1;
		// cout << k << " hi\n";
		for(i=1;i<n;i++)
		{

			a=(node[i-1]-arr[i-1])*2;
			m=atnode[i+1]+arr[i];
			if(a>m)
			{
				node[i]=m;
			}
			else
			{
				node[i]=a;
			}
			k+=node[i];
			// cout << k << " hi\n";
		}
		k+=arr[n];
		// cout << k << " hi\n";
	}
	if(n==0 && arr[0]>1)
		b=1;
	else if(n==0)
		k=1;
	if(b)
		cout << "-1\n";
	else
	{
		cout << k << "\n";

	}
	return 0;
}