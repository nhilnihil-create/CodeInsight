#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;

vector<vector<int>> id;
vector<vector<int>> to;
vector<int> ans;

int dfs(int v, int before=-1, int color=-1){
	int k = 1;
	rep(i, to[v].size())
	{
		if(to[v][i]==before)
			continue;
		int index = id[v][i];
		if(k==color)
			k++;
		ans[index] = k;
		dfs(to[v][i], v, k);
		k++;
	}
	return 0;
}
int main()
{
	int n;
	cin >> n;
	to.resize(n);
	id.resize(n);
	ans.resize(n);
	rep(i, n-1)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		to[a].push_back(b);
		id[a].push_back(i);
		to[b].push_back(a);
		id[b].push_back(i);
	}
	dfs(0);
	int mans = 0;
	rep(i,n-1){
		mans = max(mans, (int)to[i].size());
	}
	cout << mans << endl;
	rep(i, n - 1)
	{
		cout << ans[i] << endl;
	}
}
