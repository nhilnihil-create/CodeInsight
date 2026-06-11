#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <numeric>

#define roop(i, n) for(int i=0;i<n;i++)

using namespace std;
using ll = long long int;
using ull = unsigned long long;

float myPower(int a, int n) { // aのn乗の計算
	float x = 1;
	while (n > 0) { // 全てのbitが捨てられるまで
		if ( n & 1) { // 一番右のbitが１のとき
			x *= a;
		}
		a *= a;
		n >>= 1; // bit全体を右に1つシフトして一番右を捨てる
	}
	return x;
}

int main() {
	int in[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	int k;
	cin >> k;
	cout << in[k - 1] << endl;
	return 0;
}