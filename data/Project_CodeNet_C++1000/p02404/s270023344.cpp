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
			if (h == 1 || h == a){
				for (int i = 1; i <= b; i++) {
					cout << '#';
				}
			}
			else {
				cout << '#';
				for (int i = 1; i <= b - 2; i++) {
					cout << '.';
				}
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;
	}
}
