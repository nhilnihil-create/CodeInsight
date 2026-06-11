#include <iostream>
using namespace std;

int main()
{
	int x, total=0;

cin >> x;

	total += x/500*1000;
x = x % 500;
	total += x/5 * 5;
x = x % 5;
	
	cout << total;
return 0;
}