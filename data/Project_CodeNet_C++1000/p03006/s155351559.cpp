#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define cer(x) cerr << x <<endl
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())
#define pb push_back
#define MOD 1e9+7
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template<class T>inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

int main()
{
	int n; cin >> n;
	vector<int>x(n), y(n);
	map<pair<int, int>, int> m;
	rep(i, n)cin >> x[i] >> y[i];
	rep(i, n)for (int j = i + 1; j < n; j++)
	{
		int x_d = x[i] - x[j];
		int y_d = y[i] - y[j];
		if (x_d < 0)
		{
			x_d *= -1;
			y_d *= -1;
		}
		else if (x_d == 0 && y_d < 0)
		{
			y_d *= -1;
		}
		auto p = make_pair(x_d, y_d);
		m[p]++;
	}
	int ma_pair = 0;
	for (auto e:m)
	{
		if (e.second > ma_pair)ma_pair = e.second;
		cer(e.first.first << " " << e.first.second << " " << e.second);
	}
	int ans = n - ma_pair;
	co(ans);
	return 0;
}