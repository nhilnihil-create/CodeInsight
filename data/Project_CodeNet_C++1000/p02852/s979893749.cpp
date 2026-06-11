#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define rep3(i, s, n) for (int i = s; i > (int)(n); i--)
#define all(obj) obj.begin(), obj.end()
#define db(x) cerr << #x << ":" << x << " "
#define dbl(x) cerr << #x << ":" << x << "\n"
#define dbv(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define dbvv(vv) cerr << #vv << ":\n"; for (auto vec : vv) { for (auto e : vec) cerr << e << " "; cerr << endl; }
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
/*
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
*/

int main() {
	int N; cin >> N;
	int M; cin >> M;
	string S; cin >> S;
	bool f = true;
	string ans = "";
	int x = N;
	while (x > 0) {
		// db(x);
		bool g = false; // 進めるマスがあるか
		rep3(i, min(M, x), 0) {
			// db(i);
			if (S.at(x - i) == '0') {
				g = true;
				x -= i;
				ans = to_string(i) + " " + ans;
				break;
			}
		}
		if (!g) {
			f = false;
			break;
		}		
	}
	if (f) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
}