#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define INF 1LL << 60
#define MAX 1000000000
#define mod 1000000007
ll power(ll x,ll p){ll a=1;while(p>0){if(p%2==0){x*=x;p/=2;}else{a*=x;p--;}}return a;}
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll c(ll n, ll k) { ll a = 1; rep(i, 0, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll k) { ll a = 1, b = 1; rep(i, 0, k) { a = a * (n - i + 1) % mod; b = b * i % mod; }return a * mpower(b, mod - 2) % mod; }

const double PI = 3.14159265358979323846;
int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }
int main() {
	char t;
	deque<char> str;
	while (1) {
		scanf("%c", &t);
		if (t == '\n')break;
		str.push_back(t);
	}
	int c = 1, a = 0, b = 0;
	ll ans = 0, k;
	rep(i, 0, str.size() - 1) {
		if (str[i] == str[i + 1])c++;
		if(str[i] != str[i + 1] || i == str.size() - 2){
			ans += c / 2;
			c = 1;
		}
	}
	scanf("%lld", &k);
	ans *= k;
	c = 0;
	rep(i, 0, str.size()) {
		if (str[i] == str[0])c++;
		else break;
	}
	a = c;
	if (a == str.size()) {
		ans = a * k / 2;
	}
	else {
		if (str.front() == str.back()) {
			c = 0;
			for (int i = str.size() - 1; i >= 0; i--) {
				if (str[i] == str[str.size() - 1])c++;
				else break;
			}
			b = c;
			ans -= (a / 2 + b / 2) * (k - 1);
			ans += (a + b) / 2 * (k - 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}