#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define chmax(x, y) x = max(x, y)
using namespace std;

int mx = 0;
int n;
string s;


int nextfree = 1;
class trie {
	uint32_t d[20] = {0};
public:
	int first;
	int depth;

	int nxt(int i) {
		int s = i * 24, t = s + 24;
		int sa = s / 32, sb = s % 32;
		int ta = t / 32, tb = t % 32;
		if (sa == ta) {
			return d[sa] & ((1 << 24) - 1);
		}
		return (d[sa] >> sb) | ((d[ta] & ((1 << tb) - 1)) << (24 - tb));
	}
	void setnxt(int i, uint32_t v) {
		int s = i * 24, t = s + 24;
		int sa = s / 32, sb = s % 32;
		int ta = t / 32, tb = t % 32;
		if (sa == ta) {
			d[sa] = v | ((d[sa] >> 24) << 24);
			return;
		}
		d[sa] = d[sa] & ((1 << sb) - 1) | (v << sb);
		d[ta] = ((d[ta] >> tb) << tb) | (v >> (24 - tb));
	}
	//trie(int f, int d): first(f), depth(d) {}
} t[5000 * 5001 / 2 * 5 / 6];

void f(int i_nxt, int first, trie& pre) {
	if (i_nxt >= n || i_nxt - first > n / 2) return;
	int tc = s[i_nxt] - 'a';
	if (pre.nxt(tc) == 0) {
		pre.setnxt(tc, nextfree++);
		t[pre.nxt(tc)].first = first;
		t[pre.nxt(tc)].depth = pre.depth + 1;
	}
	trie& now = t[pre.nxt(tc)];
	int d = now.depth;
	if (now.first + d <= first) {
		chmax(mx, d);
	}
	return f(i_nxt + 1, first, now);
}

int main() {
	cin >> n;
	cin >> s;
	rep(i, n) {
		f(i, i, t[0]);
	}
	cout << mx << endl;
}

