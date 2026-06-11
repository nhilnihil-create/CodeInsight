#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (true == ((a < b) ? ((b < c) ? true : false) : false)) {
				cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

    return 0;

}