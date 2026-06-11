#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
#include <iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

int main() {
	long long A, B, C, K;
	long long max = 0, tmp;

	cin >> A >> B >> C >> K;

	if (K <= 0) goto END;
	if (A <= K) max += 1 * A;
	else max += 1 * K;
	
	K -= A;
	if (K <= 0) goto END;

	K -= B;
	if (K <= 0) goto END;

	if (C <= K) max -= 1 * C;
	else max -= 1 * K;

END:	cout << max << endl;
		return 0;
}