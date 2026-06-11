#include <iostream>
#include <algorithm>
using namespace std;

const int mxN = 2e5 + 5;
int a[mxN], b[mxN];

int main() {
	long long n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	sort(a + 1, a + n + 1 , greater<int>());
	sort(b + 1, b + n + 1);
	long long low = 0, high = 1e13, mid, answer = 1e14;
	while(low <= high) {
		mid = (low + high) / 2;
		long long required = 0;
		for(int i = 1; i <= n; ++i) {
			required += max((long long) 0, a[i] - (mid / b[i]));
		}
		if(required <= k) {
			answer = min(answer, mid);
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << answer;
}
