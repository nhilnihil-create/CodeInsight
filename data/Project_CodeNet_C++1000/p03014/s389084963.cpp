#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int H, W;
	cin >> H >> W;
	char S[H][W];
	int Y[H][W], T[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> S[i][j];
			Y[i][j] = -1;;
			T[i][j] = -1;
		}
	}
	for(int i=0;i<H;i++){
		if(S[i][0] == '#')Y[i][0] = 0;
		else{
			int cnt = 1;
			while(cnt < W && S[i][cnt] == '.' )cnt++;
			Y[i][0] = cnt;
		}
		for(int j=1;j<W;j++){
			if(S[i][j] == '#')Y[i][j] = 0;
			else{
				if(Y[i][j-1] > 0)Y[i][j] = Y[i][j-1];
				else{
					int cnt = 1;
					while(j+cnt < W && S[i][j+cnt] == '.')cnt++;
					Y[i][j] = cnt;
				}
			}
		}
		// cout << i << ":";
		// for(int j=0;j<W;j++){
		// 	cout << Y[i][j] << " ";
		// }
		// cout << endl;
	}
	for(int i=0;i<W;i++){
		if(S[0][i] == '#')T[0][i] = 0;
		else{
			int cnt = 1;
			while(cnt < H && S[cnt][i] == '.')cnt++;
			T[0][i] = cnt;
		}
		for(int j=1;j<H;j++){
			if(S[j][i] == '#')T[j][i] = 0;
			else{
				if(T[j-1][i] > 0)T[j][i] = T[j-1][i];
				else{
					int cnt = 1;
					while(j + cnt < H && S[j + cnt][i] == '.')cnt++;
					T[j][i] = cnt;
				}
			}
		}
	}
	// for(int i=0;i<W;i++){
	// 	cout << i << ":";
	// 	for(int j=0;j<W;j++){
	// 		cout << T[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int ans = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			ans = max(T[i][j] + Y[i][j] - 1, ans);
		}
	}
	cout << ans << endl;
}