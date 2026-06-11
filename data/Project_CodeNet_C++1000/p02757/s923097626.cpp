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
using namespace std;
//LLONG_MAX = 90^18
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No"); }
void Yes() { cout << "Yes"; }
void No() { cout << "No"; }
//max_element

int N, P;
string S;
vector<int> s;

//int r[200010];
int mod_cnt[100010];

signed main()
{
	cin >> N >> P;
	cin >> S;
	for (char ch : S) s.push_back(ch - '0');
	int len = s.size();

	if (P == 2 || P == 5)
	{
		int ans = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			if (s[i] % P == 0)
			{
				ans += (i + 1);
			}
		}
		cout << ans << endl;
		return 0;
	}

	int cur = 0;
	int ten = 1;
	int ans = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		cur = (s[i] * ten + cur) % P;
		ten = (ten * 10) % P;
		if (cur == 0) ans++;
		ans += mod_cnt[cur];
		mod_cnt[cur]++;
	}
	cout << ans << endl;
}


