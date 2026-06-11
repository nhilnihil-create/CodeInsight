#include <iostream>

using namespace std;

int main() {
	int x;
	const int mx = 123456 * 2;
	int a[mx + 1];
	for (int i = 0; i <= mx; i++) a[i] = true;
	a[0] = false;
	a[1] = false;
	for (int i = 2; i <= mx; i++) {
	    if (a[i]) {
	        for (int j = i * 2; j <= mx; j += i) {
	            a[j] = false;
	        }
	    }
	}
	while(cin >> x, x) {
	    int y = 0;
	    for (int i = x + 1; i <= 2 * x; i++) {
	        if (a[i]) y++;
	    }
	    cout << y << endl;
	}
}
