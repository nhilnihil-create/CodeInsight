#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	string s;
	cin >> s;
	reverse(all(s));
	V<ll> md13(13);
	md13[0]++;
	int k = 1;
	rep(i, s.size()) {
		
		V<ll> trans(13);

		if (0 <= s[i] - '0' && s[i] - '0' <= 9) {
			int l = (s[i] - '0') * k;
			rep(j, 13)trans[(l + j) % 13] = md13[j];
		}
		else {
			rep(j, 13)rep(p, 10) {
				trans[(p*k + j) % 13] += md13[j];
				trans[(p * k + j) % 13] %= MOD;
			}
		}
		md13 = trans;
		k *= 10;
		k %= 13;
	}

	cout << md13[5] << endl;

}