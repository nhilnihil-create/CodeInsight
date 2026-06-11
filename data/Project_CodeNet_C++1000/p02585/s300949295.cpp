#define NguyenDangQuan the_author
#define my_heart love_you_to_the_moon_and_back

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

bool typetest;
inline void fastIOfileinput()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	typetest = 0;
}

const int N = 5e3 + 3;
int n;
int p[N];
ll c[N], cur[N];
int num[N], k;

void Read()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i)
	{
		int piv = i;
		do
		{
			++num[i];
			piv = p[piv];
			cur[i] += c[piv];
		} while (piv != i);
	}
}

void Solve()
{
	ll ans = -1e18;
	for (int i = 1; i <= n; ++i)
	{
		if (cur[i] > 0 && k / num[i] > 0)
		{
			ll score = (k / num[i] - 1) * cur[i];
			ans = max(score, ans);
			int K = k - (k / num[i] - 1) * num[i];
			int piv = i;
			do
			{
				--K;
				piv = p[piv];
				score += c[piv];
				ans = max(ans, score);
			} while (piv != i && K > 0);
			if (K > 0)
			{
				piv = i;
				do
				{
					--K;
					piv = p[piv];
					score += c[piv];
					ans = max(ans, score);
				} while (piv != i && K > 0);
			}
		}
		else
		{
			int piv = i;
			int K = k;
			ll score = 0;
			do
			{
				--K;
				piv = p[piv];
				score += c[piv];
				ans = max(ans, score);
			} while (piv != i && K > 0);
		}
	}
	cout << ans;
}

int32_t main()
{
	fastIOfileinput();
	if (typetest)
	{
		int t;
		cin >> t;
		while (t--)
		{
			Read();
			Solve();
		}
	}
	else
	{
		Read();
		Solve();
	}
}