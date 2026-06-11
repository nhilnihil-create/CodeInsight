#include<bits/stdc++.h>
using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	vector<string> field(h);
	for(int i=0; i<h; i++) cin >> field[i];

	vector<vector<int>> L(h,vector<int>(w,0));
	vector<vector<int>> R(h,vector<int>(w,0));
	vector<vector<int>> D(h,vector<int>(w,0));
	vector<vector<int>> U(h,vector<int>(w,0));

	for (int i=0; i<h; i++){
		int cnt = 1;
		for (int j=0; j<w; j++){
			if (field[i][j]=='#') cnt = 0;
			L[i][j] = cnt;
			cnt++;
		}
	}

	for (int i=0; i<h; i++){
                int cnt = 1;
                for (int j=w-1; 0<=j; j--){
			if (field[i][j]=='#') cnt = 0;
                        R[i][j] = cnt;
                        cnt++;
		}
        }

	for (int j=0; j<w; j++){
                int cnt = 1;
                for (int i=0; i<h; i++){
                        if (field[i][j]=='#') cnt = 0;
                        U[i][j] = cnt;
                        cnt++;
                }
        }

	for (int j=0; j<w; j++){
                int cnt = 1;
                for (int i=h-1; 0<=i; i--){
                        if (field[i][j]=='#') cnt = 0;
                        D[i][j] = cnt;
                        cnt++;
                }
        }
	
	int ans = 0;
	for (int i=0; i<h; i++){
		for (int j=0; j<w; j++){
			if (field[i][j] == '#') continue;
			int res = L[i][j]+R[i][j]+U[i][j]+D[i][j]-3;
			ans = max(ans,res);
		}
	}

	cout << ans << endl;

	return 0;
}