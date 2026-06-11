#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,d;
	cin >> n >> d;
	vector<vector<int>> P(n, vector<int>(d));
	for(int i=0; i<n; i++){
		for(int j=0; j<d; j++){
			cin >> P[i][j];
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int norm = 0;
			for(int k=0; k<d; k++){
				int diff = abs(P[i][k]-P[j][k]);
				norm += diff*diff;
			}
			bool flag = false;
			for(int k=0; k<=norm; k++){
				if(k*k==norm) flag = true;
			}
			if(flag) ans++;
		}
	}
	cout << ans;
	return 0;
}