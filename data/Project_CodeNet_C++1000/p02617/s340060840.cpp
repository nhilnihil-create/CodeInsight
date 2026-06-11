#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ii pair < int, int >
#define iii pair < int, ii >
#define INF 987654321
#define LINF 987654321987654321

/*
node num = edge num + cc
cc = node num - edge num
*/

int main()
{
	cio;
	ll n;
	cin >> n;

	ll tot = 0;

	for (int i = 1; i <= n; i++)
		tot += i * (n - i + 1);

	for (int i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;

		if (u > v) swap(u, v);

		tot -= u * (n - v + 1);
	}

	cout << tot;
}