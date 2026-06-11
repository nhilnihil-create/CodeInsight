#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n, d;
	cin >> n >> d;
	vector<vector<int>> x(n, vector<int>(d));
	rep(i, n){
		rep(j, d){
			cin >> x.at(i).at(j);
		}
	}

	int cnt = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n;j++){
			int dist = 0;
			for(int k = 0; k < d; k++){
				int tmp = x.at(j).at(k) - x.at(i).at(k); 
				dist += tmp*tmp;
			}

			bool res = false;
			for(int n = 1; n <= dist; n++){
				if(n*n == dist) res = true;
			}

			if(res) cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}
