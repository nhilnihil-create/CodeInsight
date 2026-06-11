#include<iostream>
#include<string>
using namespace std;

int main() {

	int N;
	string c;
	cin >> N >> c;

	int cntR = 0;
	for (int i = 0; i < N; i++) {
		if (c[i] == 'R') cntR++;
	}
	int ans = 0;
	for (int i = 0; i < cntR; i++) {
		if (c[i] == 'W') ans++;
	}

	cout << ans << endl;

	return 0;
}