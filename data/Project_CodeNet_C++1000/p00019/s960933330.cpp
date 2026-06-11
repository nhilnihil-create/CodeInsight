#include <iostream>

using namespace std;

int main(void) {
	int n=0;
	long long int r=1;
	cin >> n;
	for (int i=1; i <= n; i++)
	{
		r *= i;
	}
	cout << r << endl;
}