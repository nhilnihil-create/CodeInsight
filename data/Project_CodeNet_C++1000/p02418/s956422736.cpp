#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string str, str2;
	cin >> str;
	str += str;
	cin >> str2;

	if(str.find(str2) != string::npos) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}