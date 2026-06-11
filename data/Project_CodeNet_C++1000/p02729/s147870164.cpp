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
	int N, M;
	cin >> N >> M;
	int ans = 0;

	if (N >= 2)
		ans = N * (N - 1) / 2;
	if (M >= 2)
		ans += M * (M - 1) / 2;
	cout << ans << endl;

}

int main() {
//	while(1)
	func();
	return 0;
}
