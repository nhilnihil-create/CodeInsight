#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;

int sum(vector<int> v) {
	int res = 0;
	for (auto x : v)res += x;
	return res;
}

int main(void) {
	int N, M; cin >> N >> M;
	vector<int> ac(N, 0);
	vector<int> pen(N, 0);

	rep(unchi, M) {
		int p; string s; cin >> p >> s;
		p--;
		if (ac[p])continue;
		if (s == "AC")ac[p] = 1;
		else pen[p]++;
	}

	rep(i, N) {
		if (ac[i] == 0)pen[i] = 0;
	}

	cout << sum(ac) << " " << sum(pen) << endl;

	return 0;
}