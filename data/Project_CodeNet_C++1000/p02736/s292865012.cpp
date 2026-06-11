#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
#define pir pair<int, int> 
#define all(x) (x).begin(), (x).end()
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
	return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 1e6 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 74e-9;

lli bp(lli a, lli b = -2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}


int n;
string s, t;
int fact[N];
int V2(int a)
{
	int ret = 0;
	while (a % 2 == 0)ret++, a /= 2;
	return ret;
}
int main()
{
	fastio;
	cin >> n >> s;
	for (int i = 0; i < s.length() - 1; i++)
	{
		t += abs(s[i] - s[i + 1]) + '0';
	}
	if (n == 2)
	{
		cout << t << endl;
		return 0;
	}
	int a = 0, b = 0;
	bool bl = false;
	for (int i = 1; i <= n; i++)
	{
		fact[i] = fact[i - 1] + V2(i);
	}
	for (int i = 0; i < t.length(); i++)
	{
		if (t[i] == '1') bl = true;
		if (fact[i] + fact[n - 2 - i] == fact[n - 2]) a ^= (t[i] % 2), b ^= (t[i] == '2');
	}
	if (a == 1)
	{
		cout << a << endl;
		return 0;
		vector<int> fp;
		cout << fp[0];
	}
	else if (bl) cout << 0 << endl;
	else cout << b * 2 << endl;
	return 0;
}


/*
  __
*(><)*
  \/ /
  ||/
--||
  ||
  /\
 /  \
/    \
*/
