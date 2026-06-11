#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<stack>

using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a == 0)break;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (i == 0 ||i==a-1|| j == 0 || j == b - 1)cout << "#";
				else cout << ".";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}