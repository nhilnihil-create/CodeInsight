#include <iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<ctime>
#include<functional>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<tuple>
#include<cassert>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<iomanip>
#include<climits>
#include<typeinfo>
#include<utility>
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(ll i=0;i<n;i++)
#define For(i,m,n) for(int i=m;i<n;i++)
#define FOR(i,m,n) for(ll i=m;i<n;i++)
double pi = 3.141592653589793238;
using ll = long long;
using namespace std;

ll LGCD(ll x, ll y) { if (x % y == 0) return y;else return LGCD(y, x % y); }
ll LLCM(ll x, ll y) { return x * y / LGCD(x, y); }

int GCD(int x, int y) { if (x % y == 0) return y;else return GCD(y, x % y); }
int LCM(int x, int y) { return x * y / GCD(x, y); }
ll dpcombination[10000][10000];

ll modi = 1000000007;
ll combination(ll n, ll r) {
	if (n == r) { return dpcombination[n][n] = 1; }
	else if (r == 0) { return dpcombination[n][0] = 1; }
	else if (r == 1) { return dpcombination[n][1] = n; }
	else if (dpcombination[n][r]) { return dpcombination[n][r]; }
	else { return dpcombination[n][r] = combination(n - 1, r - 1) % modi + combination(n - 1, r) % modi; }
}

void clockman(int time1) {

	cout << 1.0*(clock() - time1) / CLOCKS_PER_SEC << endl;
	return;
}
//cout << fixed << setprecision(10)

void printVec(std::vector<int> &vec) {
	std::cout << "";
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


int main() {
	int mod = 1000000007;
	int n, m;
	cin >> n >> m;
	vector<int>a(m);
	vector<int>b(n+1);
	b[0] = 0;
	for (int i = 0;i < m;i++) {
		cin >> a[i];
		b[a[i]] = 1;
		if (i > 0) {
			if (a[i]- a[i - 1] == 1) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	vector<int>d(n + 1);
	d[0] = 1;
	if (b[1] == 1)d[1] = 0;
	else d[1] = 1;

	for (int i = 2;i < n+1;i++) {
		if (b[i] == 1)d[i] = 0;
		else {
			d[i] = (d[i - 1] + d[i - 2]) % mod;
		}

	}
	for (int i = 0;i < n;i++) {
		//cout << b[i] << " " << d[i] << endl;
	}


	cout << d[n] << endl;

	return 0;
}