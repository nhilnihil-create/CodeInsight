#include<iostream>
using namespace std;
int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	cout << a / b << " " << a % b << " " << a / b << "." << (a % b) * 1000000 / b << endl;
		return 0;
}