#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, D;
	cin >> N >> D;

	vector<vector<int>> X(N, vector<int>(D));
	rep(i,N){
		rep(j,D){
			cin >> X[i][j];
		}
	
	}
	int ans = 0;

	for(int i = 0;i<N-1;i++){
		for(int j = i + 1;j < N; j++){
			int tmp = 0;
			bool ok = false;
			rep(k, D){
				tmp += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
			}
			for(int k = 1;k <= 126;k++){
				if(tmp == k * k){
					ok = true;
					break;
				}
			}
			if(ok){
			   	ans++;
		//		cout << i  <<  " " << j << " " << sqrt(tmp) << endl;
			}
		}

	}
	cout << ans << endl;
}












