#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int rest = c - (a - b);
	if (rest <= 0) cout << 0 << endl;
	else  cout << rest << endl;
}