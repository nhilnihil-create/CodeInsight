#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<string>
#include<deque>
typedef long long ll;
#define PB	push_back
#define vi(v)			vector<int> v
#define vii(v)			vector<pair<int,int>> v
#define pii(p)			pair<int,int> p
#define mii(m)			map<int, int> m
#define msi(m)			map<string, int, less<>> m
#define mmsi(m)			multimap<string, int, less<>> m
#define mkp(a,b)		make_pair(a,b)
#define ALL(obj)		obj.begin(), obj.end()
#define print(mes)		cout << mes << endl
const double PI	 = 3.141592;
const int	 MOD = 1e9 + 7;
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 1; i < n; ++i) ans += i;
	for(int i = 1; i < m; ++i) ans += i;
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}