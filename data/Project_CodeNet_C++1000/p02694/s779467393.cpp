#include<iostream>
using namespace std;

int main() {
	long long goal = 0;
	cin >> goal;

	long long box = 100;
	int ans = 0;

	while(goal > box) {
		box += box / 100;
		ans++;
	}

	cout << ans << endl;
}