#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	char a[3];

	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}

	if (a[0] == '7' || a[1] == '7' || a[2] == '7') {
		cout << "Yes" << "\n";
	}
	else {
		cout<<"No"<<"\n";
	}
}