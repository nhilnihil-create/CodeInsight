#include <iostream>
#include <string>
using namespace std;

int from_mcxi(string str)
{
	int num = 0;
	int temp = 1;

	for (unsigned int i = 0; i < str.size(); i++) {
		if (str.substr(i, 1) == "m") {
			num += temp * 1000;
			temp = 1;
		}
		else if (str.substr(i, 1) == "c") {
			num += temp * 100;
			temp = 1;
		}
		else if (str.substr(i, 1) == "x") {
			num += temp * 10;
			temp = 1;
		}
		else if (str.substr(i, 1) == "i") {
			num += temp;
			temp = 1;
		}
		else {
			temp = stoi(str.substr(i, 1));
		}
	}

	return num;
}

string to_mcxi(int x)
{
	string str;

	for (int i = 1000; i >= 1; i /= 10) {
		int temp = x / i;
		x %= i;
		if (temp == 0) {
			continue;
		}
		else if (temp >= 2) {
			str += to_string(temp);
		}

		switch (i) {
		case 1000:
			str += "m";
			break;
		case 100:
			str += "c";
			break;
		case 10:
			str += "x";
			break;
		case 1:
			str += "i";
			break;
		}
	}

	return str;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str1, str2;
		cin >> str1 >> str2;

		cout << to_mcxi(from_mcxi(str1) + from_mcxi(str2)) << endl;
	}

	return 0;
}