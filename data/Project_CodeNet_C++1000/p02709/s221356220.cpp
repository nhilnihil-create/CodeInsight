#include<bits/stdc++.h>
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define ppb pop_back
#define orta ((bas+son)>>1)
#define st first
#define nd second
#define ll long long
#define N 2005
#define inf 100000000000000ll
#define MOD 998244353
#define LOG 31
#define EPS 0.000000001
#define M 305
#define PI 3.14159265359
using namespace std;

int n;
ll dp[2][N];
ll ans;
ii a[N];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].st;
		a[i].nd = i + 1;
	}
	sort(a, a + n, greater<ii>());
	for(int i = 0; i < n; i++) {
		int cur = i & 1;
		int nxt = !cur;
		fill(dp[nxt], dp[nxt] + n + 1, 0);
		for(int s = 0; s <= i; s++) {
			if(s + 1 <= a[i].nd) 
				dp[nxt][s + 1] = max(dp[nxt][s + 1], dp[cur][s] + (ll) a[i].st * (a[i].nd - (s + 1)));
			if(a[i].nd <= n - (i - s))
				dp[nxt][s] = max(dp[nxt][s], dp[cur][s] + (ll) a[i].st * ((n - (i - s)) - a[i].nd));
		}
		ans = max(ans, *max_element(dp[nxt], dp[nxt] + n + 1));
	}
	cout << ans;

}