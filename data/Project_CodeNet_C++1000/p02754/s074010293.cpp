#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long n, a, b, ans = 0;
	cin >> n >> a >> b;
	cout << n / (a + b) * a + min(n % (a + b), a) << endl;
}