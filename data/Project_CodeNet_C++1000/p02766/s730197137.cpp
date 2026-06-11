#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	ll n;
	int k;
	cin >> n >> k;
	int count = 0;

	while (n / k > 0) {
		n /= k;
		count++;
	}
	cout << count + 1 << endl;

}