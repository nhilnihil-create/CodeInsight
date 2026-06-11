// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define exf(x)	 for(auto&& tmp : x) { cout << tmp << endl; }	// 拡張for
#define PI 3.14159265358979323846264338327950288
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)
typedef long long ll;
using namespace std;

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

int main(void) {

	int N, K, Q; cin >> N >> K >> Q;
	vector<int> cnt(N, 0);
	rep(i, Q) {
		int x;
		cin >> x;
		cnt[x - 1]++;
	}

	rep(i, N) {
		if (K - (Q - cnt[i]) > 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
