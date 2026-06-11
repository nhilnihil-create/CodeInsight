#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool turn = 0;
	while(min(a, c) > 0) {
		if(!turn)
			c -= b;
		else
			a -= d;
		if(min(a, c) < 1)
			break;
		turn ^= 1;
	}
	cout << (turn ? "No" : "Yes");
}
