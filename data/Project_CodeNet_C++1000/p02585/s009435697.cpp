#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <unordered_set>
#include <stack>
#include <queue>
#include <bitset>

#define MOD 1000000007
#define pi 3.14159265358979

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> p(n), c(n);

	for (int i = 0; i < n; i++) { cin >> p[i]; p[i]--; }
	for (int i = 0; i < n; i++) cin >> c[i];
	
	vector<bool> visited(n, false);

	ll ans = -1e18;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			int index = i;
			ll loopSum = 0;
			ll loopLen = 0;
			vector<int> loop;

			while (!visited[index])
			{
				visited[index] = true;
				loopSum += c[index];
				loopLen++;
				loop.push_back(index);
				index = p[index];
			}

			ll cycles = k / loopLen;

			if (cycles == 0)
			{
				ll tAns = c[loop[0]];

				for (int start = 0; start < loopLen; start++)
				{
					ll tmp = 0;
					for (int j = 0; j < k; j++)
					{
						tmp += c[loop[(start + j) % loopLen]];
						tAns = max(tAns, tmp);
					}
				}
				ans = max(ans, tAns);
			}
			else
			{
				//do cycles - 1 cycle and then bruteforce
				ll tAns = c[loop[0]];
				for (int start = 0; start < loopLen; start++)
				{
					ll tmp = 0;
					for (int j = 0; j < k % loopLen + loopLen; j++)
					{
						tmp += c[loop[(start + j) % loopLen]];
						tAns = max(tAns, tmp);
					}
				}
				ans = max(ans, tAns + max((cycles-1) * loopSum, (ll)0));
			}
		}
	}

	cout << ans;

	return 0;
}
