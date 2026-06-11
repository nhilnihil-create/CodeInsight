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

	int a, b;
	cin >> a >> b;
	int aa = (a + 1) / 0.08, bb = b / 0.1;

	for (int i = bb; i <= aa; i++) {
		if (floor(i * 0.08) == a && floor(i * 0.1) == b) {
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}
