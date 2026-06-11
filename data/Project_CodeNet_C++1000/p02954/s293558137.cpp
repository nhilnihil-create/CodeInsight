#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}

template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}


signed main(void) {
	string s;
	cin >> s;
	int n = s.size();
	vector<int>a(n, 0);
	vector<int>ret(n, 0);
	int countr = 0;
	int countl = 0;
	rep(i, n) {
		if (s[i] == 'R') {
			countr++;
			a[i] = countr;
		}
		else countr = 0;
	}
	rrep(i, n) {
		if (s[i] == 'L') {
			countl++;
			a[i] = countl;
		}
		else countl = 0;
	}
	rep(i, n-1) {
		if (s[i] == 'R'&&s[i + 1] == 'L') {
			ret[i] += (a[i] + 1) / 2;
			ret[i+1] += a[i]/ 2;
			ret[i+1] += (a[i+1] + 1) / 2;
			ret[i] += a[i+1] / 2;
		}
	}
	for (auto b : ret) {
		print(b);
	}
}