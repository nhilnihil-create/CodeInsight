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

using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype

template <class T>
int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define popcount __builtin_popcount

const double EPS = 1e-10;
typedef long long ll;
typedef pair<int, int> pint;


int main()
{
	bool sabori[30];
	fill(sabori, sabori + 30, true);
	for (int i = 0; i < 28; ++i)
	{
		int t;
		scanf("%d", &t);
		sabori[t-1] = false;
	}
	for (int i = 0; i < 30; ++i)
		if (sabori[i])
			printf("%d\n", i+1);
}