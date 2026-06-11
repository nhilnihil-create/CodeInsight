#include <iostream>
using namespace std;

int main()
{
	int S, h, m, s, rem;

	cin >> S;
	h = S / 3600;
	rem = S % 3600;
	m = rem / 60;
	s = rem % 60;


	cout << h << ':' << m << ':' << s << endl;

	return 0;
}