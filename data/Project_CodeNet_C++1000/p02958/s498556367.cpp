#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N;
	cin >> N;
	vector<int> p(N);
	rep(i, N) cin >> p[i];
	vector<int> q(N);
	q = p;
	sort(q.begin(), q.end());
	int cnt = 0;
	rep(i, N){
		if (p[i] != q[i]) cnt++;
	}
	string ans;
	if (cnt == 2 || cnt == 0) ans = "YES";
	else ans = "NO";
	cout << ans << endl;
	return 0;
}
