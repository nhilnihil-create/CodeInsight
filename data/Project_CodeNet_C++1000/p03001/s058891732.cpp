#include <bits/stdc++.h>

using namespace std;

int main() {


	
	double W, H, x, y;
	cin >> W >> H >> x >> y;

	double area = W * H / 2;

	printf("%f ", area);
	if (x * 2 == W && y * 2 == H) cout << 1;
	else cout << 0;


	return 0;
}