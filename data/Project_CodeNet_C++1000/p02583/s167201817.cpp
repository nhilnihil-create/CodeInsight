#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vi legs;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		legs.pb(a);
	}
	sort(legs.begin(), legs.end());

	int c = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (legs[i] + legs[j] > legs[k] && legs[i] != legs[j] && legs[i] != legs[k] && legs[j] != legs[k])
					c++;
			}
		}
	}
	cout << c;
}