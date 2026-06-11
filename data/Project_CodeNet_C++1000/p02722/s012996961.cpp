#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

unordered_set<long long> ans;

bool check(long long x, int y) {
	while (!(x%y)) x /= y;
	if (x%y == 1) return true;
	else return false;
}

void f(long long n) {
	if (n == 2) {
		ans.insert(2);
		return;
	}
	ans.insert(n), ans.insert(n - 1);
	for (int i = 2; i < sqrt(n - 1) + 1; i++) {
		if ((n - 1)%i == 0) {
			ans.insert(i), ans.insert((n - 1)/i);
		}
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			if (check(n, i)) ans.insert(i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin >> n;
	f(n);
	cout << ans.size();
}