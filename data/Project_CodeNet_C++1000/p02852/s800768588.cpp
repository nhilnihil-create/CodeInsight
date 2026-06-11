#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(obj) obj.begin(), obj.end()
#define debug(x) cerr << #x << ":" << x << " "
#define debugln(x) cerr << #x << ":" << x << "\n"
#define vdebug(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define vvdebug(vv) cerr << #vv << ":\n"; for (auto vec : vv) { for (auto e : vec) cerr << e << " "; cerr << endl; }
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main () {
	int N, M; cin >> N >> M;
	string S; cin >> S;
	vi ans = {}; bool f = true;
	while (N > 0 && f) {
		// debugln(N);
		for (int k = M; k >= 0; k--) {			
			// debug(k); vdebug(ans);
			if (N - k >= 0 && S.at(N - k) == '0') {
				ans.push_back(k);
				N -= k;
				break;
			}
			if (k == 1) f = false;
		}
	}	
	if (f) {
		reverse(all(ans));
		for (int k : ans) {
			cout << k << " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}	
}