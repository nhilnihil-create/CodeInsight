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

	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	double sum = 0;
	rep(i, N) {
		cin >> A[i];
		sum += A[i];
	}

	sort(A.begin(), A.end(), greater<int>());

	if ((sum / (4 * M)) <= (double)A[M-1]) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
