#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>


using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define clear(arr, val) memset(arr, val, sizeof(arr))

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pint;

const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


bool ok(const string& s)
{
	int maru = 0, sika = 0;
	stack<char> use;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			++maru;
		else if (s[i] == ')')
			--maru;
		else if (s[i] == '[')
			++sika;
		else if (s[i] == ']')
			--sika;

		if (strchr("([", s[i]))
			use.push(s[i]);
		else if (strchr(")]", s[i]))
		{
			if (use.empty())
				return false;

			char last = use.top(); use.pop();
			if (last == '(' && s[i] == ']'
				|| last == '[' && s[i] == ')')
				return false;
		}
	}
	return maru == 0 && sika == 0;
}
int main()
{
	string s;
	while (getline(cin, s), s.size() > 1 || s[0] != '.')
		puts(ok(s) ? "yes" : "no");
}