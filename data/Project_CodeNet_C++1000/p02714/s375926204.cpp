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
#define ll long long
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
	int n;
	string s;
	cin >> n >> s;
	ll r = 0;
	ll g = 0;
	ll b = 0;
	rep(i,n) {
		if (s[i] == 'R')r++;
		else if (s[i] == 'G')g++;
		else if (s[i] == 'B')b++;
	}
	ll ans = r * g*b;
	rep(i, n) {
		rep1(j, n) {
			//cout << i << " " << i + j << " " << i + 2 * j << endl;
			if ((i + 2*j)>=n)continue;
			else if (s[i] != s[i + j] && s[i + j] != s[i + 2 * j] && s[i + 2 * j] != s[i]) {
				ans--;
				//cout << s[i] << " " << s[i + j] << " " << s[i + 2 * j] << endl;
			}
		}
	}
	print(ans);
}