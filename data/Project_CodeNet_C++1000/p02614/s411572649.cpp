#include <bits/stdc++.h>
using namespace std;
int main(){
	int h, w, k, total=0;
	cin >> h >> w >> k;
	char grid[h+1][w+1];
	for(int i=0; i<h; ++i){
		for(int j=0; j<w; ++j){
			cin >> grid[i][j];
		}
	}
	for(int i=0; i<=(1<<h)-1; ++i){
		for(int j=0; j<=(1<<w)-1; ++j){
			int b=0;
			//cout << i << " " << j << endl;
			for(int m=0; m<h; ++m){
				for(int l=0; l<w; ++l){
					//cout << ((i>>m)&1) << " " << ((j>>l)&1) << " " << grid[m][l] << endl;
					if(((i>>m)&1)==0 && ((j>>l)&1)==0 && grid[m][l] == '#'){
						b++;
					}
				}
			}
			//cout << b << endl;
			if(b==k){
				total++;
			}
		}
	}
	cout << total;
}
