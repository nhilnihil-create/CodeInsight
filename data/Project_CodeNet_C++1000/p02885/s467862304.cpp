#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;
void warps(vector<vector<string>> s, vector<vector<int>> warp, int kaisuu, int h, int w, int x, int y);
//
//void walk(vector<vector<string>> s,vector<vector<int>> warp,int kaisuu,int h,int w,int x,int y) {
//	int flag = 0;
//	warp[x][y] = kaisuu;
//	if (x != 0) {
//		if (s[x - 1][y] == "." && warp[x - 1][y] != kaisuu) {
//			warp[x - 1][y] = kaisuu;
//			walk(s, warp, kaisuu, h, w, x - 1, y);
//		}
//		else if (s[x - 1][y] == "#") {
//			flag = 1;
//		}
//	
//	}
//	if (y != 0) {
//		if (s[x][y - 1] == "." && warp[x][y - 1] != kaisuu) {
//			warp[x][y - 1] = kaisuu;
//			walk(s, warp, kaisuu, h, w, x, y - 1);
//		}
//		else if (s[x][y - 1] == "#") {
//			flag = 1;
//		}
//	}
//	if (x != h - 1) {
//		if (s[x + 1][y] == "." && warp[x + 1][y] != kaisuu) {
//			warp[x + 1][y] = kaisuu;
//			walk(s, warp, kaisuu, h, w, x + 1, y);
//		}
//		else if (s[x + 1][y] == "#") {
//			flag = 1;
//		}
//	}
//	if (y != w - 1) {
//		if (s[x][y + 1] == "." && warp[x][y + 1] != kaisuu) {
//			warp[x][y + 1] = kaisuu;
//			walk(s, warp, kaisuu, h, w, x, y + 1);
//		}
//		else if (s[x][y + 1] == "#") {
//			flag = 1;
//		}
//	}
//
//}
//
//void warps(vector<vector<string>> s, vector<vector<int>> warp, int kaisuu, int h, int w, int x, int y) {
//	for (int i = x - 2;i <= x + 2;i++) {
//		if (i < 0 || i >= h)continue;
//		for (int j = y - 2;j <= y + 2;j++) {
//			if (j < 0 || j >= w)continue;
//			if (warp[i][j] == -1 && s[i][j] == ".") {
//				warp[i][j] = kaisuu;
//			}
//		}
//	}
//}
//
//int main() {
//	int h, w;
//	cin >> h >> w;
//	int ch, cw, dh, dw;
//	cin >> ch >> cw >> dh >> dw;
//	vector<vector<string>> s(h,vector<string> (w));
//	vector<vector<int>> warp(h, vector<int>(w));
//	for (int i = 0;i < h;i++) {
//		for (int j = 0;j < w;j++) {
//			cin >> s[i][j];
//			warp[i][j] = -1;
//		}
//	}
//
//	walk(s, warp, 0, h, w, ch, cw);
//
//	cout << warp[dh][dw] << endl;
//
//	return 0;
//}

int main() {
	int a, b;
	cin >> a >> b;

	if (a - b * 2 > 0) {
		cout << a - b * 2 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}