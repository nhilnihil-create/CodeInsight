#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, R;
	cin >> N >> R;
	cout << ((10 <= N) ? R : (R + 100 * (10 - N))) << endl;
	return 0;
}
