#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int answer = 0;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		answer += x >= k;
	}
	cout << answer;
}
