#include <iostream>
using namespace std;
int main()
{
	int n;
	int x = 0;
	cin >> n;
	while (n > x)
		x = x + 1000;
	cout << x-n<<endl;
}