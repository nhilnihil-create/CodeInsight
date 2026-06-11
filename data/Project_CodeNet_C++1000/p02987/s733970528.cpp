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
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

int main() {

	string s;
	cin >> s;
	map<char, int> mp;
	int ok = 0;
	rep(i, s.size()) {
		if (mp[s[i]] == 1)ok++;
		mp[s[i]]++;
	}
	if (ok == 2)cout << "Yes" << endl;
	else cout << "No" << endl;

}