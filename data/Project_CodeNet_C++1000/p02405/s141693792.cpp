#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_chessboard(int H, int W);
string build_row(int W, string bw);

int main() {
	int H, W;
	while(cin >> H >> W){
		if (H == 0 && W == 0) break;
		print_chessboard(H, W);
	}
}

void print_chessboard(int H, int W){
	vector<string> rows {build_row(W, "#."), build_row(W, ".#")};
	for (int h=0; h != H; ++h){
		cout << rows[h % 2] << endl;
	}
	cout << endl;
}

string build_row(int W, string bw){
	string row;
	for (int w=1; w < W; w += 2){
		row += bw;
	}
	if (W % 2){
		row += bw[0];
	}
	return row;
}