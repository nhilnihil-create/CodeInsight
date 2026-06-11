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
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
//max_element

const int r = 1;
const int s = 2;
const int p = 3;

int N, K;
int R, S, P;
int T[100010];
int ans[100010];

int win(int a)
{
	switch (a)
	{
		case r: return p;
		case s: return r;
		case p: return s;
	}
}

signed main()
{
	cin >> N >> K;
	cin >> R >> S >> P;
	string t;
	cin >> t;
	int len = t.length();
	REP(i, len)
	{
		switch (t[i])
		{
			case 'r': T[i] = r; break;
			case 's': T[i] = s; break;
			case 'p': T[i] = p; break;
		}
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (i < K)
		{
			ans[i] = win(T[i]);
		}
		else
		{
			int w = win(T[i]);
			if (ans[i - K] == w)
			{
				ans[i] = 0;
			}
			else
			{
				ans[i] = w;
			}
		}

		switch (ans[i])
		{
			case r: sum += R; break;
			case s: sum += S; break;
			case p: sum += P; break;
		}
	}

	cout << sum << endl;
}

