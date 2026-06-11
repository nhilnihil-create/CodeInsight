#include<string>
#include<iostream>
#include <algorithm>
#include<vector>
#include<functional>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <math.h>
#define ll long long 
#define PI 3.14159265358979323846
#define INF 10000000000
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
using namespace std;

int main() {
	ll N, M, ans = 0;
	cin >> N >> M;
	vector<ll> s(M), c(M);
	rep(x, M) cin >> s[x] >> c[x];
	rep(i, 1000) {
		ll keta = 1;
		vector<ll> x(1, i % 10);
		ll nx = i / 10;
		while (nx) {
			keta++;
			x.push_back(nx % 10);
			nx /= 10;
		}
		reverse(x.begin(), x.end());
		if (keta != N) continue;
		bool sx = true;
		rep(j, M) if (x[s[j] - 1] != c[j]) sx = false;
		if (sx) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;

return 0;
}
