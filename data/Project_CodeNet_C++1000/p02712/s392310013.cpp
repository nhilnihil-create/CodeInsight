#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 1; i <= n; ++i) {
		if(i % 5 == 0 || i % 3 == 0)
			continue;
		sum += i;
	}
	cout << sum;
}
