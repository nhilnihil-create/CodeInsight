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

// ------------------ ベクター合計 ------------------ //

int sumVec(vector<int> v) {
	int sum = 0;
	for (size_t i = 0; i < v.size(); i++) sum += v[i];
	return sum;
}


int main(void) {

	int N; cin >> N;
	vector<int> B(N - 1); rep(i, N - 1) cin >> B[i];
	vector<int> ans(N - 1, 0);
	ans[0]++;
	ans[N - 2]++;

	rep(i, N - 1) {
		if (i == 0) continue;
		if (B[i - 1] < B[i]) ans[i - 1]++;
		else ans[i]++;
	}
	
	ll X = 0;
	rep(i, N - 1) X += ans[i] * B[i];
	
	cout << X << endl;
	return 0;
}
