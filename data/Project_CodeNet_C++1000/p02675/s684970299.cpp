#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N;

int main() {
	cin >> N; N %= 10;
	if (N == 2 || N == 4 || N == 5 || N == 7 || N == 9) cout << "hon" << endl;
	if (N == 0 || N == 1 || N == 6 || N == 8) cout << "pon" << endl;
	if (N == 3) cout << "bon" << endl;
	return 0;
}