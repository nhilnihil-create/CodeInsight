#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	string s; cin >> s;
	vi dp(n+1, -1);
	vi dp2(n+1, 0);

	queue<int> q;
	q.push(0);
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '1') continue;
		while(!q.empty() && q.front()+m<i)
			q.pop();
		if(q.empty()){
			cout << "-1\n";
			return 0;
		}
		dp[i] = dp[q.front()]+1;
		dp2[i] = q.front();
		q.push(i);
	}

	vi ans(1, n);
	int last = n;
	while(last){
		last = dp2[last];
		ans.PB(last);
	}
	reverse(all(ans));

	for(int i = 1; i <= dp[n]; i++){
		cout << ans[i]-ans[i-1] << ' ';
	}

	return 0;
}