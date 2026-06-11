#include <cstdio>
#include <iostream>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int n, b, f, r, v;
int board[4][3][10];
int main() {
	cin >> n;
	rep(i,n) {
		cin >> b >> f >> r >> v;
		board[b - 1][f - 1][r - 1] += v;
	}
	rep(i,4) {
		rep(j,3) {
			rep(k,10) {
				cout << " " << board[i][j][k];
			}
			cout << endl;
		}
		if(i != 3) {
			rep(j,20) {
				cout << "#";
			}
			cout << endl;
		}
	}
	return 0;
}