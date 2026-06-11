#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main()
{
	unsigned int a, b;
	string sa,sb;
	while (cin >> a && cin >> b)
	{
		stringstream ss;
		ss << (a + b);
		cout << ss.str().size() << endl;
	}
	return 0;
}