#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;

using namespace std;

const int inf = 1e6 + 7;

int main(){	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> x(n),y(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j < a[i]; j++){
			int xx , yy;
			cin >> xx >> yy;
			xx--;
			x[i].push_back(xx);
			y[i].push_back(yy);
		}
	}
	
	vector<vector<int>> bit((1 << n));
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if(i & (1 << j))bit[i].push_back(1);
			else bit[i].push_back(0);
		}
	}
	
	int ans = 0;
	for(int i = 0; i < (1 << n); i++){
		bool ok = true;
		for(int j = 0; j < n; j++){
			if(bit[i][j] == 0)continue;
			for(int k = 0; k < x[j].size(); k++){
				if(bit[i][x[j][k]] == y[j][k])continue;
				ok = false;
			}
		}
		if(ok)ans = max(ans , __builtin_popcount(i));
	}
	
	cout << ans << endl;
				
	return 0;
}
 