/*DavitMarg*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <stack>
#include <cassert>
#include <iterator>
#include <fstream>
#define mod 1000000007ll
#define LL long long
#define LD long double
#define MP make_pair
#define PB push_back
#define all(v) v.begin(), v.end()
using namespace std;

const int N = 5*200005;

int n, f[N], a[N],ans,fnd1;

void init()
{
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		int c = i;
		while (c)
		{
			if (c % 2)
				break;
			f[i]++;
			c /= 2;
		}
	}
}

int c(int n, int k)
{
	if (n < k)
		return 0;
	return (f[n] - f[k] - f[n - k] < 1);
}

int main()
{
	cin >> n;
	init();
	for (int i = 1; i <= n; i++)
	{
		char x;
		scanf(" %c", &x);
		a[i] = x - '0' - 1;
		ans ^= ((a[i] % 2) * c(n - 1, i-1)) % 2;
		fnd1 += (a[i] == 1);
	}

	if (ans == 1)
		cout << ans << endl;
	else if (fnd1)
		cout << 0 << endl;
	else
	{
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i] /= 2;
			ans ^= (a[i] * c(n - 1, i-1)) % 2;
			ans %= 2;
		}
		cout << ans * 2 << endl;
	}

	return 0;
}



/*

10
2311312312


	
3
1 3 1
2 2
0

*/