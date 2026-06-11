#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	char* ret = "No";
	if (a < b && b < c)
	{
		ret = "Yes";
	}
	cout << ret << endl;
	return 0;
}