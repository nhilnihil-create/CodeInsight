#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

ll lpow(ll p, ll q) {
	ll ans = 1;
	ll pp = p;
	while (q) {
		if (q % 2) {
			ans *= pp;
			ans %= MOD;
		}
		q /= 2;
		pp *= pp;
		pp %= MOD;
	}
	return ans;
}

int main() {

	string s;
	cin >> s;

	ll mod[13];
	mod[0] = 1;
	rep1(j, 12)mod[j] = 0;

	int k = 1;

	rep1(i, s.size()) {

		ll copy[13];
		rep(j, 13)copy[j] = 0;

		if (s[s.size() - i] == '?')rep(l,10)rep(j, 13)copy[(j + k * l) % 13] += mod[j];
		else {
			int l = s[s.size() - i] - '0';
			rep(j, 13)copy[(j + k * l) % 13] += mod[j];
			
		}
		rep(j, 13)mod[j] = copy[j] % MOD;
		k *= 10;
		k %= 13;
	}

	cout << mod[5] << endl;
}