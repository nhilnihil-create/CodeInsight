#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using ULL = unsigned long long;



void solve() {
	int n; cin >> n;
	int np = 1 << n;
	vector<int> s(np); rep(i, np) cin >> s[i];
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	vector<int> d(np);

	d[0] = s[0]; s[0] = 0;

	for(int i = 0; i < n; i++) {
		int iii = 0;
		int ns = (1 << i);
		sort(d.begin(), d.begin() + ns);
		reverse(d.begin(), d.begin() + ns);
		for (int ii = 0; ii < ns; ii++) {
			while (true) {
				if (iii >= np) { cout << "No" << endl; return; }
				if (s[iii] == 0)iii++;
				else if (s[iii] >= d[ii])iii++;
				else {
					d[ii + ns] = s[iii];
					s[iii] = 0;
					iii++; break;
				}
			}
		}
	}
	cout << "Yes" << endl;
}

int main() {

	solve();

	return 0;
}
