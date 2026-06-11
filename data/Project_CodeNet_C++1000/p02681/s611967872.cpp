#include <iostream>
#include<string>
using namespace std;
int main()
{
	string s, t;
	cin >> s >> t;
	if (s + t.back() == t)
		cout << "Yes";
	else
		cout << "No";
}