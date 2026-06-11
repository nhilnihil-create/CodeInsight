#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

int n, k, c;
string s;
int l[MAX], r[MAX], cnt[MAX];

void solve() {
	cin >> n >> k >> c >> s;
	memset(l, 0, sizeof l);
	// memset(r, 0, sizeof r);
	fill(r, r+MAX, k+1);
	fill(cnt, cnt+MAX, 0);
	for(int i=1; i<=n; i++) {
		if(s[i-1] == 'o') {
			if(i <= c) l[i]++;
			else l[i] = l[i-c-1]+1;
		} else {
			l[i] = l[i-1];
		}
	}
	for(int i=n; i; i--) {
		if(s[i-1] == 'o') {
			if(i+c >= n) r[i]--;
			else r[i] = r[i+c+1]-1;
		} else {
			r[i] = r[i+1];
		}
	}
	for(int i=1; i<=n; i++) {
		if(s[i-1] == 'o' && l[i] == r[i]) cnt[l[i]]++;
	}
	for(int i=1; i<=n; i++) {
		if(s[i-1] == 'o' && l[i] == r[i] && cnt[l[i]] == 1) cout << i << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

