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
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; print(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	map<int, int> mp;
	vector<int> v;
	rep(i, 0, n) { int t; read(t); mp[t]++; }
	if (mp.size() == 1 && mp.begin()->first == 0) die("Yes");
	if (n % 3 != 0) die("No");
	for (auto p : mp) rep(i, 0, p.second / (n / 3)) v.push_back(p.first);
	if (v.size() != 3) die("No");

	if ((v[0] ^ v[1]) == v[2] && (v[0] ^ v[2]) == v[1] && (v[1] ^ v[2]) == v[0]) die("Yes");
	else die("No");
}
