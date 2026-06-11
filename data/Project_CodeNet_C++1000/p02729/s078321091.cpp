#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	cout << (A * (A - 1) / 2) + (B * (B - 1) / 2) << endl;
	return 0;
}