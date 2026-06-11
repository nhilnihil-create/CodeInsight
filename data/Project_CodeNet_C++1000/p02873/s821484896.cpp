#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
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

int keta(int x) {
	int y = 0;
	while (x > 0) {
		y++;
		x /= 10;
	}
	return y;
}

ll dx[8] = { 0,0,-1,1 };
ll dy[8] = { -1,1,0,0 };

//long longしか使わない
int main() {
	string s;
	cin >> s;
	ll n = s.length() + 1;
	vector<ll>a(n);
	rep(i, n-1) {
		if (s[i] == '<')a[i + 1] = max(a[i + 1], a[i] + 1);
	}
	for (ll i = n - 2;i >= 0;--i) {
		if (s[i] == '>')a[i] = max(a[i], a[i + 1] + 1);
	}
	ll ans = 0;
	rep(i, n) {
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}
