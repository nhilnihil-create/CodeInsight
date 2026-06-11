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
			for (int j = 0; j < b; j++)
				cout << "#";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}