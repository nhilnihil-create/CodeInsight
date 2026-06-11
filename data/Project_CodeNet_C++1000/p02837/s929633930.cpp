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

int N;
int A[16];
int X[16][16];
int Y[16][16];

int ma = 0;
int cnt = 0;
bool flg[16];

bool check()
{
	bool is_valid = true;
	for (int i = 1; i <= N; i++)
	{
		if (flg[i])
		{
			for (int j = 0; j < A[i]; j++)
			{
				if (Y[i][j] == 1 && !flg[X[i][j]])
				{
					is_valid = false;
				}
				if (Y[i][j] == 0 && flg[X[i][j]])
				{
					is_valid = false;
				}
			}
		}
	}
	return is_valid;
}

void func(int depth)
{
	if (depth > N)
	{
		if (check())
		{
			ma = max(ma, cnt);
		}
		return;
	}

	flg[depth] = false;
	func(depth + 1);
	cnt++;
	flg[depth] = true;
	func(depth + 1);
	cnt--;
}

signed main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		REP(j, A[i])
		{
			cin >> X[i][j] >> Y[i][j];
		}
	}
	func(1);
	cout << ma << endl;
}

