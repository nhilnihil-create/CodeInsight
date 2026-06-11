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
#define CLEAR(arr, val) memset(arr, val, sizeof(arr))

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pint;

const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		string s;
		cin >> s;

		set<string> used;
		int res = 0;
		for (int i = 1; i < s.size(); ++i)
		{
			string a[2], b[2];
			a[0] = s.substr(0, i), b[0] = s.substr(i);
			a[1] = a[0], b[1] = b[0];
			reverse(all(a[1]));
			reverse(all(b[1]));

			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					string c = a[j], d = b[k];
					for (int l = 0; l < 2; ++l)
					{
						string cat = c + d;
						if (!used.count(cat))
						{
							++res;
							used.insert(cat);
						}
						swap(c, d);
					}
				}
			}
		}
		cout << res << endl;
	}
}