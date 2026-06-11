#include <iostream>
#include<vector>
#include<array>
#include<cmath>
#include <algorithm>

using namespace std;
#define ull unsigned long long

int main() {
	// 初期処理(iostream軽くする)
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	ull n;
	cin >> n;
	vector<ull> v;

	for (ull i = 0; i < n; i++) {
		if (((i+1) % 3 == 0)||((i+1)%5==0)) {
			v.push_back(0);
		}else {
			v.push_back(i+1);
		}
	}
	ull sum = 0;
	for (ull i = 0; i < n; i++) {
		sum += v[i];
	}
	cout << sum;
	return 0;
}