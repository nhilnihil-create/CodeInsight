#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int ans = (N + 1000 - 1) / 1000 * 1000 - N;
	cout << ans << endl;
	return 0;
}