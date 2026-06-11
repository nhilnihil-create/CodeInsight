#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep2(i,n) for(int i = (n - 1); i >= 0; i--)
#define PI 3.141592653589793

using namespace std;
using ll = long long;

int to[200000];

int main() {

	int n;
	ll xo;
	cin >> n;
	vector<ll> a(n);
	 rep(i, n) {
		 cin >> a[i];
		 if (i == 0)xo = a[i];
		 else xo ^= a[i];
	 }

	 rep(i, n) {
		 ll ans = xo ^ a[i];
		 cout << ans << endl;
	 }
	return 0;
}