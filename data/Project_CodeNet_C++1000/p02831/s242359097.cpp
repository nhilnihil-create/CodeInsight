#include <iostream>
#include <algorithm>

using namespace std;

long long lcm(long long a, long long b)
{
	return a / __gcd(a, b) * b;
}

int main()
{
	long long A, B;
	cin >> A >> B;
	cout << lcm(A, B) << endl;

	return 0;
}