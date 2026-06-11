#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	ll x,ans=100,count=0;
	cin >> x;
	while (ans < x) {
		ans += ans / 100;
		count++;
	}
	cout << count << endl;
}