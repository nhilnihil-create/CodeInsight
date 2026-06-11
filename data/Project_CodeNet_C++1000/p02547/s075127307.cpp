#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define ex(k) (a*(b-n)+(a-b)*(k)-(k)*(k))
using namespace std;

void solve()	{
	int n;
	cin >> n;
	int d[n][2];
	for(int i=0; i<n; i++)	{
		cin >> d[i][0] >> d[i][1];
	}
	for(int i=0; i<n-2; )	{
		if(d[i][0]==d[i][1])	{
			int l=0;
			while(d[i][0]==d[i][1])	{
				l++;
				i++;
			}
			if(l>2)	{cout << "Yes\n"; return;}
		}
		else i++;
	}
	cout << "No\n";
}

int main()	
{
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}