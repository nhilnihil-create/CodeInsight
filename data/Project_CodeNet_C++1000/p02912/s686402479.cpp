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

ll sumVec(vector<int> v) {
	ll sum = 0;
	for (size_t i = 0; i < v.size(); i++) sum += v[i];
	return sum;
}

int main(void) {

	int N, M; cin >> N >> M;
	priority_queue<int> A;
	rep(i, N) {
		int a;
		cin >> a;
		A.push(a);
	}
	
	while (M) {
		int tmp = A.top();
		A.pop();
		A.push(tmp/2);
		M--;
	}

	ll sum = 0;
	while (!A.empty()) {
		sum += A.top();
		A.pop();
	}
	cout << sum << endl;
	return 0;
}
