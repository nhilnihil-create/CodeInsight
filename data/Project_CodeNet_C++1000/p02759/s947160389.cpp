#include<iostream>
#include <vector>

using namespace std;

int main()
{
	uint16_t n;
	cin >> n;

	cout << static_cast<uint16_t>((n+1)/2) << endl;
	return 0;
}