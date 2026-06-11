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

double to_deg(double r) {
	return r * 180.0 / (atan(1.0) * 4.0);
}


signed main(void) {
	double a, b,d;
	cin >> a >> b >> d;
	double ans = 0;
	if ((a*a*b)/2<d) {
		ans = atan(pow(a, 3) / (2*(a*a*b-d)));
	}
	else {
		ans = atan((2 * d)/(a*b*b));
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(7) << (90-to_deg(ans));
}