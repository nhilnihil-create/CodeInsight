#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s, p;
	cin >> s;
	cin >> p;

	s += s;
	if (s.find(p) == string::npos) cout << "No\n";
	else cout << "Yes\n";
}