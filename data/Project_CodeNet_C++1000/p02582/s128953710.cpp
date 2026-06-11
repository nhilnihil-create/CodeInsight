#include<iostream>
#include<string>

using namespace std;

int main() {
	
	std::string str;
	
	cin >> str;

	if (str == "RSR") {
		cout << 1 << endl;
	}
	else if (str == "RSS") {
		cout << 1 << endl;
	}
	else if (str == "SRS") {
		cout << 1 << endl;
	}
	else if (str == "SSR") {
		cout << 1 << endl;
	}
	else if (str == "SRR") {
		cout << 2 << endl;
	}
	else if (str == "RRS") {
		cout << 2 << endl;
	}
	else if (str == "RRR") {
		cout << 3 << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}