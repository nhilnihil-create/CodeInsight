#include <iostream>

using namespace std;

int main()
{
	string N;
	cin >> N;

	if (N[N.length() - 1] == '2'
		|| N[N.length() - 1] == '4'
		|| N[N.length() - 1] == '5'
		|| N[N.length() - 1] == '7'
		|| N[N.length() - 1] == '9') {
		cout << "hon" << endl;

	}
	else if (N[N.length() - 1] == '0'
		|| N[N.length() - 1] == '1'
		|| N[N.length() - 1] == '6'
		|| N[N.length() - 1] == '8') {
		cout << "pon" << endl;
	}
	else if (N[N.length() - 1] == '3') {
		cout << "bon" << endl;
	}

}



