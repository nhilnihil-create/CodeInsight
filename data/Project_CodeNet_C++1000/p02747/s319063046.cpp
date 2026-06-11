#include <iostream>
#include <string>
using namespace std;

string s, t;

int main()
{
	cin >> s;

	int n = s.size() / 2;

	for (int i = 0; i < n; i++)
		t += "hi";

	if(s == t)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
