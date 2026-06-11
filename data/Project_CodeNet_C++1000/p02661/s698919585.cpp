#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector <ll> lower;
vector <ll> upper;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll i,j,k,l,m,n,t,a,b;

	cin >> n;

	for(i=0;i<n;i++)
	{
		cin >> a >> b;
		lower.push_back(a);
		upper.push_back(b);
	}

	sort(lower.begin(),lower.end());
	sort(upper.begin(),upper.end());

	if(n%2 == 0)
	{
		l = lower[n/2]+lower[n/2-1];
		k = upper[n/2]+upper[n/2-1];
	}	
	else
	{
		l = lower[n/2];
		k = upper[n/2];
	}

	cout << k - l +1 << '\n';
}