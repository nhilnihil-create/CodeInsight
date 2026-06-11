#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll n,a[100],sum=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				sum+=a[i]*a[j];
			}
		}	
		cout<<sum;

   return 0;
}
