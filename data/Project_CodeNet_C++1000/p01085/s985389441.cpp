#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps=1e-8;
int main() {
	int n, s, g;
	while (cin >> n >> s >> g, n) {
		int x[300];
		rep(i, n) {
			cin >> x[i];
		}
		sort(x, x + n,greater<int>());
		int ma = 0; int chk;
		Rep1(i,s,g) {
			if (ma <= x[i - 1]-x[i]) {
				ma = x[i - 1] - x[i]; chk = i;
			}
		}
		cout << chk << endl;
	}
	return 0;
}
