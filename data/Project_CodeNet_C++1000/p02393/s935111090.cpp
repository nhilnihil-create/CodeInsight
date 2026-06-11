// class point	の練習（クラスの高度な実装）
#include <iostream>
using namespace std;



int main() {
	int a, b, c;

	cin >> a >> b >> c;

	if (a > b&&a > c) {
		if (b > c)cout << c << " " << b << " " << a << "\n";
		else cout << b << " " << c << " " << a << "\n";
	}
	else if (b > a&&b > c) {
		if (a > c)cout << c << " " << a << " " << b << "\n";
		else cout << a << " " << c << " " << b << "\n";
	}
	else {
		if (a > b)cout << b << " " << a << " " << c << "\n";
		else cout << a << " " << b << " " << c << "\n";
	}

	return 0;
}

