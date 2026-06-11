#include <iostream>
using namespace std;
int main() {
	int W, H, X, Y;
	cin >> W >> H >> X >> Y;
	cout.precision(15);
	cout << 0.5 * W * H << ' ' << (X * 2 == W && Y * 2 == H ? 1 : 0) << endl;
	return 0;
}