#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <queue>
#include <memory>
#include <fstream>

#pragma GCC optimize("no-stack-protector,Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,abm,mmx,tune=native,avx,avx2")

#define int long long
#define ld long double
#define eb emplace_back
#define pb pop_back
#define mp make_pair
#define ss second
#define ff first
#define sqr(x) (x) * (x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair < int, int >
#define vi vector < int >
#define vvi(x, y) vector < vi > (x, vi(y))

typedef int(*func)(int a, int b);

using namespace std;

random_device rd;
mt19937 get_rand(rd());

template < typename T1, typename T2 >
istream& operator>>(istream& in, pair < T1, T2 >& p) {
	in >> p.ff >> p.ss;
	return in;
}

template < typename T1, typename T2 >
ostream& operator<<(ostream& out, pair < T1, T2 >& p) {
	out << p.ff << ' ' << p.ss;
	return out;
}

template < typename T1 >
istream& operator>>(istream& in, vector < T1 >& v) {
	for (int i = 0; i < sz(v); i++)
		in >> v[i];
	return in;
}

template < typename T1 >
ostream& operator<<(ostream& out, vector < T1 >& v) {
	for (int i = 0; i < sz(v); i++)
		out << v[i] << ' ';
	out << '\n';
	return out;
}

int gcd(int a, int b) {
	return (!a ? b : gcd(b % a, a));
}

const int INF = 1e9 + 7;
const int B = 100003;
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.14159265358979323;
const int MAXLL = 9223372036854775807;


signed main() {
	//ifstream cin("kdivision.in");
	//ofstream cout("kdivision.out");
#ifdef _LOCAL
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	srand(time(NULL));

	int ttt = 1;
	//cin >> ttt;
	while (ttt--) {
		int a, b, n;
		cin >> a >> b >> n;
		int x = min(b - 1, n);
		cout << (a * x) / b << '\n';
	}
	return 0;
}