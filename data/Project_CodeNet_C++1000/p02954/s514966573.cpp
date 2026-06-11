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
	vi ans(s.size());

	int k = 0;
	rep(i, s.size()) {
		if (s[i] == 'R')k++;
		else {
			ans[i] += k / 2;
			ans[i - 1] += k - k / 2;
			k = 0;
		}
	}
	rep(i, s.size()) {
		if (s[s.size() - 1 - i] == 'L')k++;
		else {
			ans[s.size() - 1 - i] += k / 2;
			ans[s.size() - i] += k - k / 2;
			k = 0;
		}
	}

	rep(i, s.size()) {
		cout << ans[i];
		if (i < s.size())cout << " ";
		else cout << endl;
	}

}