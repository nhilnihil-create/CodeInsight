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
	int n, m;
	cin >> n >> m;
	priority_queue<int>que;
	rep(i, n) {
		int a;
		cin >> a;
		que.push(a);
	}
	rep(i, m) {
		int a = que.top();
		que.pop();
		a/= 2;
		que.push(a);
	}
	int ans = 0;
	while (!que.empty()) {
		int a = que.top();
		que.pop();
		ans += a;
	}
	print(ans);
}