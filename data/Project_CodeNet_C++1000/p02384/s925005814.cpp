#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int main() {
	int a[6], head, down;
	rep(i,6) {
		cin >> a[i];
	}
	int s[6][6];
	s[0][0] = -1, s[0][1] = 2, s[0][2] = 4, s[0][3] = 1, s[0][4] = 3, s[0][5] = -1;
	s[1][0] = 3, s[1][1] = -1, s[1][2] = 0, s[1][3] = 5, s[1][4] = -1, s[1][5] = 2;
	s[2][0] = 1, s[2][1] = 5, s[2][2] = -1, s[2][3] = -1, s[2][4] = 0, s[2][5] = 4;	
	rep2(i,3,6) {
		rep(j,6) {
			s[i][j] = s[5 - i][5 - j];
		}
	}
	int q;
	cin >> q;
	rep(i,q) {
		cin >> head >> down;
		int b, c;
		rep(i,6) {
			if(a[i] == head) b = i;
			else if(a[i] == down) c = i;
		}
		cout << a[s[b][c]] << endl;
	}
	return 0;
}
	