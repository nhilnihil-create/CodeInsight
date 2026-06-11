#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string hi = "hi";
	int i = 0;
	for (i = 0; i < 5; i++){
		if (s != hi) hi += "hi";
		else break;
	}

	if (i == 5) cout << "No" << endl;
	else cout << "Yes" << endl;
}
