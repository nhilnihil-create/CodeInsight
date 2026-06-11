#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	auto judge = [&](string a) {
		string b = a;
		reverse(b.begin(), b.end());
		return b == a;
	};
	if (!judge(s)) {
		cout << "No" << endl;
		return 0;
	}
	int n = s.size();
	if (!judge(s.substr(0, (n - 1) / 2))) {
		cout << "No" << endl;
		return 0;
	}
	if (!judge(s.substr((n + 3) / 2 - 1))) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}