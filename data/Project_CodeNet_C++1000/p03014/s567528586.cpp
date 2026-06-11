#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

int WCON[2002][2002] = {0};
int HCON[2002][2002] = {0};

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<string> S;
	for(int i=0; i<H; i++){
		string s;
		for(int j=0; j<W; j++){
			char c; cin >> c;
			s.push_back(c);
		}
		S.push_back(s);
	}
	for(int i=0; i<H; i++){
		int sum = 0;
		for(int j=0; j<W; j++){
			if(S[i][j] == '#'){
				WCON[i][j] = 0;
				sum = 0;
			}
			else{
				sum++;
				WCON[i][j] = sum;
			}

		}
		for(int j=W-2; j>=0; j--){
			if(WCON[i][j] > 0 && WCON[i][j+1] > 0){
				WCON[i][j] = WCON[i][j+1];
			}
		}
	}
	for(int j=0; j<W; j++){
		int sum = 0;
		for(int i=0; i<H; i++){
			if(S[i][j] == '#'){
				HCON[i][j] = 0;
				sum = 0;
			}
			else{
				sum++;
				HCON[i][j] = sum;
			}

		}
		for(int i=H-2; i>=0; i--){
			if(HCON[i][j] > 0 && HCON[i+1][j] > 0){
				HCON[i][j] = HCON[i+1][j];
			}
		}
	}
	int ans = 0;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			int u = HCON[i][j] + WCON[i][j] - 1;
			if(ans < u){
				ans = u;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
