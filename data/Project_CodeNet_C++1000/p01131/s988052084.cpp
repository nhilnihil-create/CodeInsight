#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
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
#define popcount __builtin_popcount
#define CLEAR(arr, val) memset(arr, val, sizeof(arr))

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pint;

const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;

		static string let[] = { "", ".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		string res;
		char button = '0';
		int n = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '0')
			{
				if (button != '0')
				{
					string& t = let[button - '0'];
					res += t[(n - 1) % t.size()];
				}

				n = 0;
			}
			else
				++n;

			button = s[i];
		}

		cout << res << endl;
	}
}