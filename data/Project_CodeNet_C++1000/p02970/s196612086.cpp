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
#define testP	 cout << "------------------ test ------------------" << endl;	// 動作確認テスト
#define testX(x) cout << "testout : " << x << endl;	// テストアウト
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)
typedef long long ll;
using namespace std;

// ------------------ ベクター表示 ------------------ //
void printVec(vector<int>& vec) {
	cout << "";
	for (auto it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
	cout << endl;
}

// ------------------ ベクター合計 ------------------ //
int sumVec(vector<int> v) {
	int sum = 0;
	for (size_t i = 0; i < v.size(); i++) sum += v[i];
	return sum;
}

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

int main(void) {

	double N, D; cin >> N >> D;
	cout << (int)ceil(N / (D * 2 + 1)) << endl;

	return 0;
}
