#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>

const int MAXN = 2e5 + 10;
typedef long long ll;

using namespace std;

int main()
{
	ll a, b, c, d, x, y;
	cin >> a >> b >> c >> d;
	ll maxn = a*c;
	maxn = max(maxn, a*d);
	maxn = max(maxn, b*c);
	maxn = max(maxn, b*d);
	cout << maxn <<endl;
	return 0;
} 