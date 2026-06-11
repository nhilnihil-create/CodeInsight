#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
	int a, b;
	int cnt = 0;
	cin >> a >> b;
	cout << a/b << " " << a%b<<" "<< setprecision(5) <<fixed<< (double)a/b<< endl;
}
