#include <iostream>
using namespace std;

int main() {
	bool ok = true;
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if(x % 2 == 0) 
			if(ok)
				ok = x % 3 == 0 || x % 5 == 0;
	}
	cout << (ok ? "APPROVED" : "DENIED");
}
