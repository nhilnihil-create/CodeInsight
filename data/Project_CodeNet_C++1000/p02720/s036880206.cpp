#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000007
#define SEP " "

int     main()
{
	int k;
	cin >> k;
	queue<ll> q;
	for (int i = 1; i < 10; i++)
	{
		q.push(i);
	}
	for (int i = 1; i < k; i++) {
		ll f = q.front();
		q.pop();
		if (f % 10 != 0)
			q.push(f * 10 + f % 10 - 1);
		q.push(f * 10 + f % 10);
		if (f % 10 != 9)
			q.push(f * 10 + f % 10 + 1);
	}
	cout << q.front() << endl;
}
