#include<bits/stdc++.h>
#include<climits>

using namespace std;

#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
#define fie(i,a,b) for(i=a;i<b;i++)
#define MOD 1000000007
#define mod 998244353
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define ll long long
#define lld long long int
#define ALL(x) (x).begin(),(x).end()

typedef vector<lld> vi;
typedef vector<vector<lld>> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pair<lld, lld>> vpi;
typedef long long LL;

//MODULAR ARITHMATIC
const int mmod = 1000000000 + 7;

lld add(lld a, lld b, lld m = mmod) {
	return (a % m + b % m) % m;
}

lld sub(lld a, lld b, lld m = mmod) {
	return (a % m - b % m + m) % m;
}

lld mul(lld a, lld b, lld m = mmod) {
	return ((a % m) * (b % m) % m);
}

lld pwr(lld a, lld b, lld m = mmod) {
	a %= m;
	lld r = 1;
	while (b) {
		if (b & 1) r = r * a % m;
		b >>= 1;
		a = a * a % m;
	}
	return r;
}

lld inv(lld a, lld m = mmod) {
	return pwr(a, m - 2, m);
}

//FACTORIAL MOD mmod
#define SIZE 1000000
lld fact[SIZE + 1];
void factorial() {
	fact[0] = 1;
	for (lld i = 1; i <= SIZE; i++) {
		fact[i] = (fact[i - 1] % mmod * (i % mmod)) % mmod;
	}
}

//NCR MOD mmod
lld nCr(lld n, lld r) {
	return (((fact[n] * inv(fact[r])) % mmod) * (inv(fact[n - r]))) % mmod;
}

lld dp[2001][2001];

lld solve(lld n, lld l) {
	if (n < 0 || n == 1 || n == 2 || l < 0) return 0;
	if ((l == 0 && n != 0) || (n == 0 && l != 0)) return dp[n][l] = 0;
	if (n == 0 && l == 0) {
		return dp[n][l] = 1;
	}
	lld c = 0;
	if (dp[n][l] != -1) return dp[n][l];
	for (lld i = 3; i <= n; i++) {
		c += solve(n - i, l - 1);
		c %= MOD;
	}
	return dp[n][l] = c;

}

int main() {
	fast;
	cin.tie(0);

	factorial();

	lld n;
	cin >> n;
	lld x = 0;
	for (lld k = 2; k <= n; k++) {
		x = add(x, mul(pwr(8, n - k), mul(nCr(n, k), sub(pwr(2, k), 2))));
	}

	cout << x << endl;
}






