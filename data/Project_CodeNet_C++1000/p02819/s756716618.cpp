#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// [0, MaxNumPlusOne - 1 ] の範囲の整数が素数であるかどうかを表す配列を返す関数
// 配列の要素が 1であれば素数
// 配列の要素が-1であれば素数でない
vector<int> Eratosthenes(int MaxNumPlusOne) {
	vector<int> isPrimeArray(MaxNumPlusOne, 1);
	int MaxNum = MaxNumPlusOne - 1;
	isPrimeArray[0] = -1;
	isPrimeArray[1] = -1;
	for (int i = 2; i <= sqrt(MaxNum); i++) {
		if (isPrimeArray[i] == 1) {
			for (int j = 2; j <= MaxNum; j++) {
				if (i * j > MaxNum) break;
				isPrimeArray[i * j] = -1;
			}
		}
	}
	return isPrimeArray;
}

int main() {

	int q; cin >> q;
	const int p = 1000001;
	vector<int> isPrimeNumber = Eratosthenes(p); // [0, p - 1] の範囲を調べる場合
	while (true) {
		if (isPrimeNumber[q] == 1) {
			break;
		}
		q++;
	}
	cout << q << endl;
    return 0;
}