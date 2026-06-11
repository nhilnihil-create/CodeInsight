#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(10000001, 1);
	for (int i = 2; i < 10000001; ++i) {
		int a = i;
		while (a <= 10000000) {
			++v[a];
			a += i;
		}
	}

	long long ret = 0;
	for (int i = 1; i <= n; ++i) {
		ret += (long long)i * (long long)v[i];
	}
	cout << ret << endl;

	return 0;
}