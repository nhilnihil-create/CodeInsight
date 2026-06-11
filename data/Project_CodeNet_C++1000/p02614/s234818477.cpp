#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	int H, W, K;
	cin >> H >> W >> K;
	vector<string> v(H);
	for(int i=0; i<H; ++i) cin >> v[i];
	int ans=0;
	for(int i=0; i<(1<<H); ++i){
		for(int j=0; j<(1<<W); ++j){
			int cnt=0;
			for(int h=0; h<H; ++h){
				for(int w=0; w<W; ++w){
					if((i&(1<<h)) && (j&(1<<w)) && v[h][w]=='#') ++cnt;
				}
			}
			if(cnt==K) ++ans;
		}
	}
	cout << ans << endl;
	return 0;
}