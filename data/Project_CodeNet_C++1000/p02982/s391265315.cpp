#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n, d;
	cin >> n >> d;
	
	vector<vector<int>> x(n, vector<int>(d));
	rep(i, n){
		rep(j, d){
			cin >> x.at(i).at(j);
		}
	}

	int ans = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			int dist = 0;
			rep(k, d){
				int now = x.at(i).at(k) - x.at(j).at(k);
				dist += now*now;
			}

			for(int n = 0; n <= dist;n++){
				if(n*n == dist) ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}

