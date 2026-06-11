#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	string s, t;
	cin >> s >> t;

	vvi chr(26);
	rep(i, s.size()) chr[s[i] - 'a'].push_back(i);

	int loop = 0, k = 0;
	rep(i, t.size()) {
		int s = lower_bound(all(chr[t[i] - 'a']), k) - chr[t[i] - 'a'].begin();
		if (s == chr[t[i] - 'a'].size()) {
			loop++;
			s = lower_bound(all(chr[t[i] - 'a']), 0) - chr[t[i] - 'a'].begin();
			if (s == chr[t[i] - 'a'].size()) {
				cout << -1 << endl;
				return 0;
			}
		}
		k = chr[t[i] - 'a'][s] + 1;
	}

	cout << loop * (ll)s.size() + k << endl;

}