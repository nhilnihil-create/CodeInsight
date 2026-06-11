#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<string>
typedef long long ll;
#define PB	push_back
#define FOR(n)			for(int i = 0; i < n; ++i)
#define RFOR(n)			for(int i = n; i >= 0; --i)
#define FORR(start,end) for(int i = start; i < end; ++i)
#define COUT(n)			cout << n << " " << flush
#define vi(v)			vector<int> v
#define vii(v)			vector<pair<int,int>> v
#define pii(p)			pair<int,int> p
#define mii(m)			map<int, int> m
#define msi(m)			map<string, int, less<>> m
#define mmsi(m)			multimap<string, int, less<>> m
#define mkp(a,b)		make_pair(a,b)
#define ALL(obj)		obj.begin(), obj.end()
const double PI	 = 3.141592;
const int	 MOD = 1e9 + 7;
using namespace std;

void solve() {
	ll n, a, b, ans = 0;
	cin >> n >> a >> b;
	ans += a * (n / (a + b));
	n -= (a+b) * (n/(a+b));
	if(n >= a) ans += a;
	else ans += n;
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}