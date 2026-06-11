#include <iostream>
#define int64 long long
using namespace std;
int main()
{
	int64 nn, mm;
	cin >> nn >> mm;
	nn = nn * (nn - 1) / 2;
	mm = mm * (mm - 1) / 2;
	cout << nn + mm << endl;
	return 0;
}
