#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
	int N;
	int m;
	cin >> N;
	m = (N % 100) / 5;
	if ((N % 100) % 5 != 0)m++;
	if (N == 100 || N == 101 || N == 102 || N == 103 || N == 104 || N == 105) cout << 1 << endl;
	else if (N < m  * 100)cout << 0 << endl;
	else cout << 1 << endl;

	return 0;
}
