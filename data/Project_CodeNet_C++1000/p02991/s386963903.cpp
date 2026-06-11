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


int N, M;
vector<int> _link[100001];
int S, T;

int _flg1[100001];
int _flg2[100001];
int _flg3[100001];
queue<int> q1;
queue<int> q2;
queue<int> q3;

signed main()
{
	cin >> N >> M;
	REP(i, M)
	{
		int u, v;
		cin >> u >> v;
		_link[u].push_back(v);
	}
	cin >> S >> T;

	REP(i, N + 1)
	{
		_flg1[i] = LLONG_MAX;
		_flg2[i] = LLONG_MAX;
		_flg3[i] = LLONG_MAX;
	}
	//memset(_flg1, LLONG_MAX, sizeof(_flg1));
	//memset(_flg2, LLONG_MAX, sizeof(_flg2));
	//memset(_flg3, LLONG_MAX, sizeof(_flg3));

	q1.push(S);
	_flg1[S] = 0;
	int s = 1;

	while (q1.size() > 0)
	{
		while (q1.size() > 0)
		{
			int n = q1.front();
			q1.pop();

			for (int l : _link[n])
			{
				if (_flg2[l] > s)
				{
					_flg2[l] = s;
					q2.push(l);
				}
			}
		}

		while (q2.size() > 0)
		{
			int n = q2.front();
			q2.pop();

			for (int l : _link[n])
			{
				if (_flg3[l] > s)
				{
					q3.push(l);
					_flg3[l] = s;
				}
			}
		}

		while (q3.size() > 0)
		{
			int n = q3.front();
			q3.pop();

			for (int l : _link[n])
			{
				if (_flg1[l] > s)
				{
					q1.push(l);
					_flg1[l] = s;
				}
			}
		}

		s++;
	}

	if (_flg1[T] == LLONG_MAX) 
		cout << -1 << endl;
	else
		cout << _flg1[T] << endl;
}

