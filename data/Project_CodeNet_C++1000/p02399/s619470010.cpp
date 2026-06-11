#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#if defined SUBLIME
#  define ISTREAM ss
#else
#  define ISTREAM cin
#endif


using namespace std;
int main()
{
	#if defined SUBLIME
		string str = "12300 99";
		stringstream ss;
		ss << str;
	#endif
	int a, b;
	double c;
	ISTREAM >> a >> b;
	c = (double) (a % b) / b;
	cout << a / b << " " << a % b << " " << fixed << setprecision(8) << (double) a / b << endl;
}