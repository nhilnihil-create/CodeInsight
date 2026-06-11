#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#ifdef _MSC_VER
int getchar_unlocked() { return getchar(); }
#endif
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << endl;
#define qp(f) [](auto i){return f;}
using LL=long long;
using VI=vector<int>;
using VL=vector<LL>;
using VS=vector<string>;
using VVI=vector<vector<int>>;
using PII=pair<int, int>;
const int inf = (int)1e9;
const LL MOD = 1000000007;
const double pi = acos(-1.0);
const string Snum = "0123456789";
const int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
template<class T>T Sort(T& a) { sort(a.begin(), a.end()); return a; }
template<class T>T ReSort(T& a) { sort(a.rbegin(), a.rend()); return a; }
template<class T>T Reverse(T& a) { reverse(a.begin(), a.end()); return a; }
template<class T>void Unique(T& a) { a.erase(unique(a.begin(), a.end()), a.end()); }
template<class T>auto Max(T a) { return *max_element(a.begin(), a.end()); }
template<class T>auto Min(T a) { return *min_element(a.begin(), a.end()); }
template<class T, class U>int Count(T a, U c) { return count(a.begin(), a.end(), c); }
template<class T, class U>U Sum(T a, U init = 0) { return accumulate(a.begin(), a.end(), init); }
template<class T>T Age(T a, T b) { return (a + b - 1) / b; }
template<class T>T gcd(T n, T m) { return m == 0 ? n : gcd(m, n % m); }
template<class T>T lcm(T n, T m) { return n / gcd(n, m) * m; }

int solve(VI& a, int p, int r) {
	int x = a[r], i = p - 1;
	FOR(j, p, r) {
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

int main() {
	int n; scanf("%d", &n);
	VI a(n); rep(i, n)scanf("%d", &a[i]);

	int pos = solve(a, 0, n - 1);
	rep(i, n) {
		if (i == pos)printf("[%d]", a[i]);
		else printf("%d", a[i]);
		printf(i == n - 1 ? "\n" : " ");
	}
}
