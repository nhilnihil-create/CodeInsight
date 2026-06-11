#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<stack>

using namespace std;

int main() {
	int n, k, count = 0;
	while (cin >> n >> k) {
		count = 0;
		if (n == 0)break;
		for (int i = 1; i <= n - 2; i++) {
			for (int j = i + 1; j * 2 < k - i; j++) {
				if (k - i - j > 0 && k - i - j <= n)count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}