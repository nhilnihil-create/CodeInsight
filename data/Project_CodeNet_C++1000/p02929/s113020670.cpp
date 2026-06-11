/*input
4
BWBBWWWB
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
int n, seq[maxn];
string s;
void zero()
{
	cout << "0\n";
	exit(0);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> s;
	if(s[0] == 'W' || s.back() == 'W')
		zero();
	// 0 - open, 1 - close
	seq[0] = 0;
	for(int i = 1; i < 2 * n; i++)
	{
		if(s[i] == s[i - 1])
			seq[i] = seq[i - 1] ^ 1;
		else
			seq[i] = seq[i - 1];
	}
	ll open = 0, ans = 1;
	for(int i = 0; i < 2 * n; i++)
	{
		if(seq[i] == 0)
			++open;
		if(open % 2 != s[i] == 'B')
			zero();
		if(seq[i] == 1)
		{
			if(open == 0)
				zero();
			ans = ans * open % mod;
			--open;
		}
	}
	if(open != 0)
		zero();
	for(ll i = 1; i <= n; i++)
		ans = ans * i % mod;
	cout << ans << "\n";
	return 0;
}