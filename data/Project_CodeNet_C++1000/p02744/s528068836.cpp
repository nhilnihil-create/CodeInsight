#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double PI = 4*atan(1);
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;
const string YES = "Possible";
const string NO = "Impossible";
#define pb push_back
#define mp make_pair

int N;
vector<string> res;

void dfs(int cnt, int tot, string tmp)
{
	if(tmp.length() == N){
		if(cnt == tot){
			res.pb(tmp);
		}
		return;
	}
	for(int i=0;i<cnt;++i){
		tmp += i+'a';
		dfs(cnt, tot, tmp);
		tmp.pop_back();
	}
	if(cnt < tot){
		tmp += cnt+'a';
		dfs(cnt+1,tot,tmp);
	}
}

void helper(int x)
{
	if(x == 1) res.pb(string(N, 'a'));
	else if(x == N){
		string t;
		for(int i=0;i<N;++i) t += i+'a';
		res.pb(t);
	}else{
		dfs(0, x, "");
	}
}

void solve()
{
	for(int i=1;i<=N;++i) helper(i);
	const int n = res.size();
	set<string> ans;
	for(int i=0;i<n;++i) ans.emplace(res[i]);
	for(auto& s : ans){
		cout << s << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
	solve();
	return 0;
}
