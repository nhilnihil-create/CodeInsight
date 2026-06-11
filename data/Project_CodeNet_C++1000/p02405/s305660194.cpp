#include <iostream>
using namespace std;

int is_odd(int a) {
	return a % 2 == 1 ? 1 : 0;
}

int is_even(int a) {
	return a % 2 == 0 ? 1 : 0;
}

int is_odd_or_even_both(int a, int b) {
	return ((is_odd(a) & is_odd(b)) || (is_even(a) & is_even(b))) ? 1 : 0;
}

int main()
{
	int h, w;
	while(1) {
		cin >> h >> w;
		if (h == 0 & w == 0) break;

		int i, j;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				cout << (is_odd_or_even_both(i, j) == 1 ? "#" : ".");
			}
			cout << "\n";
		}
		cout << "\n";
	}
}