#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int a[N];
	rep(i,N) cin >> a[i];
	set<int> b(a,a+N);
	if (b.size() > 3) {
		cout << "No" << endl;
		return 0;
	}
	vector<int> cnt(b.size());
	int k = 0;
	for (int i : b) {
		rep(j,N) {
			if (a[j] == i) cnt[k]++;
		}
		k++;
	}

	if (b.size() == 1) {
		if (*b.begin() == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else if (b.size() == 2) {
		if (*b.begin() == 0) {
			if (2*cnt[0] == cnt[1]) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
	else if (b.size() == 3) {
		int tot = 0;
		for (int i : b) tot ^= i;
		if (tot == 0) {
			if (cnt[0] == cnt[1] && cnt[1] == cnt[2]) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}

	return 0;
}
