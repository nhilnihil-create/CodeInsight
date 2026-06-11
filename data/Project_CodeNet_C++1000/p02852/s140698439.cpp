#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>
#include<deque>
#include<random>
#include<set>
#include<bitset>
#include<cassert>

using namespace std;
typedef long long ll;
typedef double lldo;
#define mp make_pair
#define pub push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else  return gcd(b, a % b); }
ll lcm(ll a, ll b) { if (a == 0) { return b; }return a / gcd(a, b) * b; }
template<class T>ll LBI(vector<T>& ar, T in) { return lower_bound(ar.begin(), ar.end(), in) - ar.begin(); }
template<class T>ll UBI(vector<T>& ar, T in) { return upper_bound(ar.begin(), ar.end(), in) - ar.begin(); }

ll n, m, cur = 0;
string s;
vector<ll> ans;

int main() {
	cin >> n >> m;
	cin >> s;
	cur = n;
	while (cur > 0) {
		bool flag = false;
		for (int i = max(cur - m, (ll)0); i < cur; i++) {
			if (s[i] == '0') {
				ans.pub(cur - i);
				cur = i;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = sz(ans) - 1; i >= 0; i--)cout << ans[i] << endl;
	return 0;
}