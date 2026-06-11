//empty sockets
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int n, i;
	n = s.length();
	s.resize(0);
	for (i = 0; i < n; i++)
	{
		s.push_back('x');
	}
	cout << s << " " << endl;

	return 0;
}

