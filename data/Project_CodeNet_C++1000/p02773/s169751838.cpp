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

	int N; cin >> N;
	vector<string> S(N); rep(i, N) cin >> S[i];
	
	sort(S.begin(), S.end());
	vector<int> cnt(N,1);
	int MAX = 1;
	for (int i = 1; i < N; i++) {
		if (S[i] == S[i - 1]) cnt[i] += cnt[i - 1];
		MAX = max(MAX, cnt[i]);
	}
	
	rep(i, N) {
		if (cnt[i] == MAX) cout << S[i] << endl;
	}
	return 0;
}
