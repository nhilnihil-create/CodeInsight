#include<iostream>

using namespace std;

int main() {
	int x, i;
	while (1) {
		cin >> x;
		if (x == 0)break;
		cout << "Case " << i + 1 << ": " << x << endl;
		i++;
	}
}