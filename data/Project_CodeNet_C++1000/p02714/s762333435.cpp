#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < (N);++i)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int N;
	string S;
	cin >> N >> S;

	vector<int> a(N);
	rep(i, N) {
		if (S[i] == 'R')a[i] = 0;
		if (S[i] == 'G')a[i] = 1;
		if (S[i] == 'B')a[i] = 2;
	}

	vector<ll> cnt(3);
	rep(i, N)cnt[a[i]]++;

	ll ans = 1;
	rep(i, 3)ans *= cnt[i];

	rep(j, N)rep(i, j) {
		int k = j + (j - i);
		if (k >= N)continue;
		if (a[i] == a[j])continue;
		if (a[j] == a[k])continue;
		if (a[k] == a[i])continue;
		ans--;
	}

	cout << ans << endl;

	return 0;
}