#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n < 11)
		return cout << n, 0;
	queue<long long> q;
	for(int i = 1; i < 10; ++i)
		q.push(i);
	int cnt = 0;
	while(cnt != n) {
		long long x = q.front();
		q.pop();
		++cnt;
		if(cnt == n)
			return cout << x, 0;
		if(x % 10 != 0)
			q.push(10 * x + x % 10 - 1);
		q.push(10 * x + x % 10);
		if(x % 10 != 9)
			q.push(10 * x + x % 10 + 1);
	}
}
