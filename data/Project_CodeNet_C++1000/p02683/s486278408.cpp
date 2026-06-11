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
const int inf = 99999999;

using namespace std;

int main(){
	int n,m,x;
	cin >> n >> m >> x;
	vector<int> c(n);
	vector<vector<int>> a(n,vector<int>(m,0));
	for(int i = 0; i < n; i++){
		cin >> c[i];
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	//bit 
	ll ans = inf;
	for(int i = 0; i < (1 << n); i++){
		ll cost = 0;
		vector<int> xall(m,0);
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				cost += c[j];
				for(int k = 0; k < m; k++){
					xall[k] += a[j][k];
				}
			}
		}
		bool ok = true;
		for(int k = 0; k < m; k++){
			if(xall[k] >= x)continue;
			ok = false;
		}
		if(ok)ans=min(ans,cost);
	}
	if(ans == inf)ans = -1;
	cout << ans << endl;
	
	return 0;
}
 