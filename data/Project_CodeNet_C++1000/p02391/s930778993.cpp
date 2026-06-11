#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	string mark;
	if (a < b) {
		mark = "<";
	}
	else if (a > b) {
		mark = ">";
	}
	else {
		mark = "==";
	}
	cout << "a " + mark + " b" << endl;
}

