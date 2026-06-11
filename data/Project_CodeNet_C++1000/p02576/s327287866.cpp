#include <iostream>
using namespace std;

int main()
{
	int n, x, t;
	cin >> n >> x >> t;
	cout << (n/x+((n%x>0)?1:0))*t << endl;
	return 0;
}