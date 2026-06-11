#include <iostream>
using namespace std;
int main()
{
	long long int H, W;
	cin >> H >> W;
	if (H == 1 || W == 1)
		cout << "1" << "\n";
	else if (H % 2 == 0)
		cout << H / 2 * W << "\n";
	else
		cout << H / 2 * W + W - W / 2 << "\n";
}