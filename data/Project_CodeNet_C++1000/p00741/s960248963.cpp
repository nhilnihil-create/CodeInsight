#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

const int INF = 100000000;

int w, h;
vector<int> ma[60];

void rec(int y, int x){
	int ny, nx;
	if(ma[y][x] != 1){
		return;
	}
	ma[y][x] = 0;
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			if(i == 0 && j == 0) continue;
			nx =  x + i;
			ny =  y + j;
			if(ny >= 0 && ny < h && nx >= 0 && nx < w){
				rec(ny, nx);
			}
		}
	}
}
int main(void) {
	while(1){
		for(int i=0; i<60; i++){
			ma[i] = vector<int>();
		}
		cin >> w >> h;
		if(w == 0 && h == 0) break;

		for(int i = 0; i < h; i++){
			for(int j=0; j<w; j++){
				int t;
				cin >> t;
				ma[i].pb(t);
			}
		}

		int ans = 0;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(ma[i][j] == 1){
					ans++;
					rec(i, j);
				}
			}
		}
		/*
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cout << ma[i][j] << ' ';
			}
			cout << endl;
		}
		*/
		cout << ans << endl;
	}
	
	return 0;
}