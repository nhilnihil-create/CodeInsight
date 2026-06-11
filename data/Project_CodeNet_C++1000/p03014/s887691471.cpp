#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll H, W;

struct cellinfo {
	int x0;
	int xlen;
	int y0;
	int ylen;
};

cellinfo ci[2001][2001];


int main(){
	cin >> H >> W;
	
	vector<string> S(H+1);
	for ( int i = 0; i < H; i++ )
		cin >> S[i];
	S[H] = S[0];
	for ( int i = 0; i < W; i++ )
		S[H][i] = '#';
	
	for ( int y = 0; y < H; y++ ){
		for ( int x = 0; x < W; x++ ){
			ci[y][x].y0 = ci[y][x].x0 = -1;
		}
	}
	
	for ( int y = 0; y < H; y++ ){
		int x0 = -1;
		for ( int x = 0; x <= W; x++ ){
			if ( S[y][x] == '.' ){
				if ( x0 == -1 ){
					x0 = x;
				}
				ci[y][x].x0 = x0;
			}
			else {
				if ( x0 != -1 ){
					ci[y][x0].xlen = x - x0;
					x0 = -1;
				}
			}
		}
	}
	
	for ( int x = 0; x < W; x++ ){
		int y0 = -1;
		for ( int y = 0; y <= H; y++ ){
			if ( S[y][x] == '.' ){
				if ( y0 == -1 ){
					y0 = y;
				}
				ci[y][x].y0 = y0;
			}
			else {
				if ( y0 != -1 ){
					ci[y0][x].ylen = y - y0;
					y0 = -1;
				}
			}
		}
	}
	
	int max_val = 0;
	for ( int y = 0; y < H; y++ ){
		for ( int x = 0; x < W; x++ ){
			int val = 0;
			if ( S[y][x] == '.' ){
				int x0 = ci[y][x].x0;
				val += ci[y][x0].xlen;
				int y0 = ci[y][x].y0;
				val += ci[y0][x].ylen;
				max_val = max(max_val, val-1);
			}
			//cout << val << " ";
		}
		//cout << endl;
	}
	cout << max_val << endl;
	
	return 0;
}

