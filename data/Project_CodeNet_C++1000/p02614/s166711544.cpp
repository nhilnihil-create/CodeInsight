#include <iostream>
using namespace std;

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	char c[h][w];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> c[i][j];
		}
	}
	//bit全探索
	char c1[h][w], c2[h][w];
	

	int ans = 0;
	for (int bit = 0; bit < (1<<h); ++bit){
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				c1[i][j] = c[i][j];
			}
		}
		for(int row = 0; row < h; ++row){
			if(bit & (1<<row)) {
				for(int j = 0; j< w; j++) c1[row][j] = 'R';
			}
		}
		for(int bit2 = 0; bit2 < (1<<w); ++bit2){
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					c2[i][j] = c1[i][j];
				}
			}
			for(int row2 = 0; row2 < w; ++row2){
				if(bit2 & (1<<row2)) {
					for(int i = 0; i< h; i++) c2[i][row2] = 'R';
				}
			}
			int count = 0;
			for(int i=0; i<h;i++){
				for(int j=0; j<w;j++){
					if(c2[i][j]=='#') count++;
				}
			}
			if(count==k){
				ans++;
			}

		}

	}
	cout << ans << endl;
	return 0;
  
}
