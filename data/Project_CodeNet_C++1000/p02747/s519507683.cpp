#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);

//pairの入力
//vector<pair<ll, ll>>work(n);
//rep(i, n) {
//	ll a, b;
//	cin >> a >> b;
//	work[i] = make_pair(a, b);
//}

int g[15][15];
const int INF = 1001001001;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

//素因数分解
vector<pair<ll, int>>factorize(ll n) {
	vector<pair<ll, int>>res;
	for (ll i = 2;i * i <= n;++i) {
		if (n % i)continue;
		res.emplace_back(i, 0);
		while (n % i == 0) {
			n /= i;
			res.back().second++;
		}
	}
	if (n != 1)res.emplace_back(n, 1);
	return res;
}

int dp[1010][1010];
int bingo[3][3];
bool flag[3][3];

ll n;
ll ans = 0;

void dfs(ll x, int a, int b, int c) {
	if (x > n)return;
	if (a && b && c)ans++;
	dfs(10 * x + 3, 1, b, c);
	dfs(10 * x + 5, a, 1, c);
	dfs(10 * x + 7, a, b, 1);
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	bool flag = true;
	if (n % 2 != 0)flag = false;
	else if (n % 2 == 0) {
		rep(i, n) {
			if (i % 2 == 0 && s[i] != 'h')flag = false;
			else if (i % 2 != 0 && s[i] != 'i')flag = false;
		}
	}
	if (flag)puts("Yes");
	else puts("No");
	return 0;
}
