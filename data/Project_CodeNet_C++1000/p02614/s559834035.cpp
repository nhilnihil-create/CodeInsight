#include <bits/stdc++.h>


using namespace std;

typedef long long int ll;

int main(){
	int h,w,k;
	cin >> h >> w >> k;
	vector<string> maze(h);
	for(int i = 0; i < h; i++){
		cin >> maze[i];
	}
	int res = 0;
	auto cnt = [&](int mask_i, int mask_j){
		int ct = 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if( !(mask_i & (1 << i)) &&  !(mask_j & (1 << j))){
					if(maze[i][j]=='#') ++ct;
				}
			}
		}
		return ct == k;
	};
	for(int mask_i = 0; mask_i < (1 << h); mask_i++){
		for(int mask_j = 0; mask_j < (1 << w); mask_j++){
			res += cnt(mask_i,mask_j);	
		}
	}
	cout << res << "\n";
	return 0;
}
