#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>
#include <stdio.h>
#include <string.h>
using ll = long long;

//LLONG_MAX
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()

using namespace std;

int N;
int X[101];
int Y[101];

using P = pair<double, double>;
P p[101];
int ary[101];

signed main()
{
	cin >> N;
	REP(i, N)
	{
		cin >> X[i] >> Y[i];

		double angle = atan2(Y[i], X[i]);
		p[i] = make_pair(angle, i);
	}

	ARY_SORT(p, N);
	
	REP(i, N)
	{
		ary[i] = p[i].second;
	}

	double ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			double x = 0.0;
			double y = 0.0;

			for (int k = 0; k < j; k++)
			{
				int index = (i + k) % N;
				x += X[ary[index]];
				y += Y[ary[index]];
			}

			double len = sqrt(x * x + y * y);
			ans = max(ans, len);
		}
	}

	cout << fixed << setprecision(10) << ans << endl;
}

