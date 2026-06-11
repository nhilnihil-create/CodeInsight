#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
double condition = 0.0;

void func()
{
	int64_t N, K;
	cin >> N >> K;

	int64_t amari = N % K;

	if (abs(amari - K) < amari)
		cout << abs(amari - K) << endl;
	else
		cout << amari << endl;
	return;
}

int main() {
//while(1)
	func();
	return 0;
}
