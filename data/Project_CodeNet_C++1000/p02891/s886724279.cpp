#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);

//pairの入力
//vector<pair<ll, ll>>work(n);
//rep(i, n) {
//	ll a, b;
//	cin >> a >> b;
//	work[i] = make_pair(a, b);
//for(auto p:mp)(mapの探索)
//printf("%.10f\n",なんちゃら)

int g[15][15];
const int INF = 1001001001;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

//素因数分解
map<ll, ll>ins;
void facterize(ll n) {
	ll a = 2;
	while (n >= a * a) {
		if (n % a == 0) {
			ins[a]++;
			ins[a] = ins[a] % 1000000007;
			n /= a;
		}
		else {
			a++;
		}
	}
	ins[n]++;
}

vector<ll>relation[20], money(20, 1);
char s[110][110];
int dp[110][110];

int main() {
	string s;
	cin >> s;
	ll k;
	cin >> k;
	ll ans = 0;
	int n = s.length();
	bool flag = true;
	rep(i, n-1) {
		if (s[i] != s[i + 1]) {
			flag = false;
			break;
		}
	}
	if (s[0] != s[n - 1]) {
		for (int i = 0;i < n-1;++i) {
			if (s[i] == s[i + 1]) {
				ans++;
				++i;
			}
		}
		ans*= k;
	}
	else {
		int a = 0, b = 0;
		for (int i = 0;i < n;++i) {
			if (s[0] == s[i]) {
				a++;
			}
			else {
				break;
			}
		}
		for (int i = n - 1;i >= 0;--i) {
			if (s[0] == s[i]) {
				b++;
			}
			else {
				break;
			}
		}
		rep(i, n - 1) {
			if (s[i] == s[i + 1]) {
				ans++;
				++i;
			}
		}
		ans *= k;
		if (a % 2 != 0 && b % 2 != 0) {
			ans += (k - 1);
		}
	}
	if (flag) {
		ans = n * k / 2;
	}
	cout << ans << endl;
	return 0;
}