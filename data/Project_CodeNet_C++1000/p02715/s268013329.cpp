#include<bits/stdc++.h>
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define ppb pop_back
#define orta ((bas+son)>>1)
#define st first
#define nd second
#define ll long long
#define N 200005
#define inf 100000000000000ll
#define MOD 1000000007
#define LOG 31
#define EPS 0.000000001
#define M 305
#define PI 3.14159265359
using namespace std;

int n, k, all;
int ans[N];

int mul(int x, int y) {

	return (ll) x * y % MOD;

}

int add(int x, int y) {

	x += y;
	while(x < 0)
		x += MOD;
	while(x >= MOD)
		x -= MOD;
	return x;

}

int fe(int base, int pow) {

	if(pow == 0)
		return 1;
	if(pow & 1)
		return mul(fe(base, pow - 1), base);
	int result = fe(base, pow >> 1);
	return mul(result, result);

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = k; i >= 1; i--) {
		int tot_num = k / i;
		ans[i] = fe(tot_num, n);
		for(int j = i + i; j <= k; j += i) 
			ans[i] = add(ans[i], -ans[j]);
		all = add(all, mul(ans[i], i));
	}
	cout << all;

}