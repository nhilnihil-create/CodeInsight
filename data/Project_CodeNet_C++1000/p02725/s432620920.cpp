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

	int K, N; cin >> K >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];

	sort(A.begin(), A.end());

	int ma = 0;
	for (int i = 1; i < N; i++){
		int bet = A[i] - A[i - 1];
		ma = max(bet, ma);
	}

	ma = max(ma, K - A[N - 1] + A[0]);
	cout << K - ma << endl;
	return 0;
}
