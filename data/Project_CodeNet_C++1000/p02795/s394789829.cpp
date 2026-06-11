#include <iostream>
using namespace std;

int main() {
	int H, W, N;
	cin >> H >> W >> N;
	cout << (H > W ? (N + H - 1) / H : (N + W - 1) / W) << endl;
}

