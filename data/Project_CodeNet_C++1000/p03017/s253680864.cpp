#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, a, b, c, d;
	string s;
	read(n, a, b, c, d, s);
	s = " " + s;

	while (a < c || b < d) {
		bool jaf = c > d;
		//printf("%d/%d %d/%d\n", a, c, b, d);
		if (jaf) {
			if (a < c) {
				if (a + 1 <= c && s[a + 1] == '.' && a + 1 != b) { a = a + 1; continue; }
				if (a + 2 <= c && s[a + 2] == '.' && a + 2 != b) { a = a + 2; continue; }
			}
			if (b < d) {
				if (b + 1 <= d && s[b + 1] == '.' && b + 1 != a) { b = b + 1; continue; }
				if (b + 2 <= d && s[b + 2] == '.' && b + 2 != a) { b = b + 2; continue; }
			}
		} else {
			if (b < d) {
				if (b + 1 <= d && s[b + 1] == '.' && b + 1 != a) { b = b + 1; continue; }
				if (b + 2 <= d && s[b + 2] == '.' && b + 2 != a) { b = b + 2; continue; }
			}
			if (a < c) {
				if (a + 1 <= c && s[a + 1] == '.' && a + 1 != b) { a = a + 1; continue; }
				if (a + 2 <= c && s[a + 2] == '.' && a + 2 != b) { a = a + 2; continue; }
			}
		}
		//printf("B %d/%d %d/%d\n", a, c, b, d);
		break;
	}

	die ((a == c && b == d) ? "Yes" : "No");
}
