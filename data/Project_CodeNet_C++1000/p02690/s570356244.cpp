#include<bits/stdc++.h>
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;

	for (ll i = -118; i <= 119; i++)
	{
		for (ll j = -119; j <= 118; j++)
		{
			if ((pow(i, 5) - pow(j, 5)) == n)
			{
				cout << i << " " << j;
				return 0;
			}
		}
	}

}

