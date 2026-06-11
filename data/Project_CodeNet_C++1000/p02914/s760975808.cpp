#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
const int M = 59;
LL a[N];
LL b[M + 10];
int cnt[M + 10];
void setzero(LL& b, int o)
{
	b |= 1LL << o;
	b ^= 1LL << o;
}
void add(LL x)
{
	for (int j = M; j >= 0; j--)
	{
		if (x >> j & 1)
		{
			if (b[j] == 0)
			{
				b[j] = x;
				break;
			}
			x ^= b[j];
		}
	}
}
void refrain()
{
	vector<LL> v;
	for (int i = 0; i <= M; i++) v.push_back(b[i]);
	MEM(b, 0);
	for (auto& x : v)
		add(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum ^= a[i];
		LL x = a[i];
		for (int j = M; j >= 0; j--)
		{
			cnt[j] += (a[i] >> j & 1);
		}
		add(a[i]);
	}
	LL ans = 0;
	LL o = 0;
	for (int i = M; i >= 0; i--)
	{
		if (cnt[i] == 0)
		{
			continue;
		}
		if (sum >> i & 1)
		{
			ans += 1LL << i;
			for (int j = 0; j <= M; j++)
			{
				setzero(b[j], i);
			}
			refrain();
			continue;
		}
		o |= 1LL << i;
		LL x = o;
		for (int j = M; j >= 0; j--)
		{
			if (x >> j & 1)
			{
				x ^= b[j];
			}
		}
		if (x & o)
		{
			o ^= 1LL << i;
			for (int j = 0; j <= M; j++)
			{
				setzero(b[j], i);
			}
			refrain();
		}
	}
	cout << ans + o * 2 << endl;
	return 0;
}