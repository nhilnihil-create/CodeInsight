#include <iostream>
using namespace std;

const int mxN = 22;
int a[mxN], b[mxN], c[mxN];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1; i < n; ++i)
		cin >> c[i];
	int answer = 0, last = -1;
	for(int i = 1; i <= n; ++i) {
		answer += b[a[i]];
		if(last + 1 == a[i])
			answer += c[last];
		last = a[i];
	}
	cout << answer;
}
