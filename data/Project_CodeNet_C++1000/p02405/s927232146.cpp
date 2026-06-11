#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long a, b; 
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) return 0;
		for (int h = 1; h <= a; h++) {
			for (int i = 1; i <= b; i++) {
				if (h % 2 == 1) {
					if (i % 2 == 1) {
						cout << '#';
					}
					else {
						cout << '.';
					}
				}
				else {
					if (i % 2 == 0) {
						cout << '#';
					}
					else {
						cout << '.';
					}
				}
			}
			cout << endl;
		}
		cout << endl;
	}
}
