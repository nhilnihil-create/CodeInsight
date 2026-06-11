#include <iostream>
#include <iomanip>
using namespace std;

int a, b;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> a >> b;

	cout << a / b << " " << a%b << " " << fixed << setprecision(5) << (double)a / (double)b << "\n";

	return 0;
}