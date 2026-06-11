#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int K;
vector<ll> ans;
const ll MAX = 3234566667;

void dfs(ll cur)
{
	if(cur > MAX) return;
	ans.push_back(cur);
	int last = cur%10;
	dfs(10*cur+last);
	if(last >= 1) dfs(10*cur+last-1);
	if(last <= 8) dfs(10*cur+last+1);
}

void solve()
{
	for(int i=1;i<=9;++i) dfs(i);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans[K-1] << '\n';
}

int main()
{
	cin >> K;
	solve();
	return 0;
}