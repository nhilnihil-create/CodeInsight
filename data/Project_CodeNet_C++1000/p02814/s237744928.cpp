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

int gcd(int a, int b)
{
	if (a%b == 0)return(b);
	else return(gcd(b, a%b));
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int cnt2(int a)
{
	int count = 0;
	while (a % 2 == 0) {
		a /= 2;
		count++;
	}
	return count;
}

signed main(void) {
	int n, m;
	cin >> n >> m;
	vector<int>a(n);
	rep(i, n) {
		cin >> a[i];
	}

	int count = cnt2(a[0]);
	rep1(i, n) {
		if (count != cnt2(a[i])) {
			print(0);
			return 0;
		}
	}

	int ans = a[0]/2;
	rep1(i, n) {
		ans = lcm(ans, a[i] / 2);
	}
	
	if ((m / ans) % 2 == 0)print(m / (ans * 2));
	else print(m / (ans * 2)+1);
	return 0;
}