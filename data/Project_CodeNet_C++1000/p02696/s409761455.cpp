#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int A;
	long long B, N;
	int ans = 0;
	cin >> A >> B >> N;

	//余りがB-1で
	long long x_max = ((N / B) - 1)*B + (B - 1);
	long long test;
	test = A * x_max / B;
	test -= A * (long long)(x_max / B);

	ans = max(ans, (int)test);

	test = A * N / B;
	test -= A * (long long)(N / B);

	ans = max(ans, (int)test);

	cout << ans << endl;
	return 0;
}