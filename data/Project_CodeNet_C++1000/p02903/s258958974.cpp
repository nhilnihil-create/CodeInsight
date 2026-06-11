#include <iostream>
#include <vector>
using namespace std;
int main() {
	int H, W, A, B;
	cin >> H >> W >> A >> B;
	A = A == 0 ? W - A : A;
	B = B == 0 ? H - B : B;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)  cout << ((i < B&& j < A) || (i >= B && j >= A) ? 1 : 0);
		cout << endl;
	}
}
