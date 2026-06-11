#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
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
#include <random>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS_VEC(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }

int N;
vector<int> link[100001];
map<int, int> ans[100001];
int A[100001];
int B[100001];
int _max = 1;

void func(int n, int from, int parent)
{
	int cur = 1;
	if (parent == cur) cur++;

	for (int l : link[n])
	{
		if (l != from)
		{
			ans[n][l] = cur;
			ans[l][n] = cur;

			func(l, n, cur);
			_max = max(_max, cur);

			cur++;
			if (parent == cur) cur++;
		}
	}
}

signed main()
{
	cin >> N;
	REP(i, N - 1)
	{
		int a, b;
		cin >> a >> b;
		A[i] = a;
		B[i] = b;
		link[a].push_back(b);
		link[b].push_back(a);
	}

	func(1, -1, -1);

	cout << _max << endl;
	REP(i, N - 1)
	{
		int n = ans[A[i]][B[i]];
		cout << n << endl;
	}
}

