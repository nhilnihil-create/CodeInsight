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

vector<int> Zalgo(string str) {
	int n = str.size();
	vector<int> a(n, 0);
	int from = -1, last = -1;
	for (int i = 1; i < n; ++i) {
		int &same = a[i];
		if (from != -1) {
			same = min(a[i - from], last - i);
			maxs(same, 0);
		}
		while (i + same < str.size() && str[same] == str[i + same]) same++;
		if (last < i + same) {
			last = i + same;
			from = i;
		}
	}
	for (int i = 1; i < n; ++i) {
		mins(a[i], i);
	}
	a[0] = n;
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		string tmp = s.substr(i);
		auto rec = Zalgo(tmp);
		for (int j = 1; j < rec.size(); ++j) {
			maxs(ans,rec[j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
