#include <iostream>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

ll lunlun(ll n) {
	queue<ll> ll_queue;
	//initialise
	for (int i = 1; i <= 9; i++) {
		ll_queue.push(i);
	}
	while (n > 1) {
		ll curr = ll_queue.front();
		ll_queue.pop();
		if (curr % 10LL > 0) {
			ll_queue.push(10LL * curr + (curr % 10LL) - 1);
		}
		ll_queue.push(10LL * curr + (curr % 10LL));
		if (curr % 10LL < 9) {
			ll_queue.push(10LL * curr + (curr % 10LL) + 1);
		}
		n--;
	}
	return ll_queue.front();
}

int main() {
	int n;
	cin >> n;
	cout << lunlun(n);
}