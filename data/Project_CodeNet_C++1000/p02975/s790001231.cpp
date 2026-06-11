#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n; cin >> n;
	vector<int> cnt(30);
	rep(i, n)
	{
		int a; cin >> a;
		rep(j, 30)
		{
			cnt[j] += a % 2;
			a /= 2;
		}
	}
	if (n % 3 == 0)
	{
		rep(i, 30)
		{
			if (cnt[i] != 0 && cnt[i] != (n / 3) * 2)
			{
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	else
	{
		rep(i, 30)
		{
			if (cnt[i] != 0)
			{
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
}