#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

string s;
bool check(int i, int j) {
	return (s[i-j] != s[i] && s[i-j] != s[i+j] && s[i] != s[i+j]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	cin >> s;
	int pr = 0, pg = 0, pb = 0;
	int sr[n], sg[n], sb[n];
	sr[n-1] = sg[n-1] = sb[n-1] = 0;
	for (int i=n-2; i>=0; i--) {
		sr[i] = sr[i+1] + (s[i+1] == 'R');
		sg[i] = sg[i+1] + (s[i+1] == 'G');
		sb[i] = sb[i+1] + (s[i+1] == 'B');
	}
	ll ans = 0;
	for (int i=0; i<n; i++) {
		ll cur = 0;
		if (s[i] == 'R') {
			cur += pg*sb[i];
			cur += pb*sg[i];
			for (int j=1; i-j>=0 && i+j<n; j++) {
				if (check(i, j)) cur--;
			}
		}
		else if (s[i] == 'G') {
			cur += pr*sb[i];
			cur += pb*sr[i];
			for (int j=1; i-j>=0 && i+j<n; j++) {
				if (check(i, j)) cur--;
			}
		}
		else {
			cur += pr*sg[i];
			cur += pg*sr[i];
			for (int j=1; i-j>=0 && i+j<n; j++) {
				if (check(i, j)) cur--;
			}
		}
		ans += cur;
		if (s[i] == 'R') pr++;
		else if (s[i] == 'G') pg++;
		else pb++;
	}
	cout << ans;
}