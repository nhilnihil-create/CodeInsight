#include <iostream>
using namespace std;

int main() {
	int n, h;
	cin >> h >> n;
	int tot = 0;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		tot += x;
	}
	if(h > tot)
		cout << "No";
	else
		cout << "Yes";
}