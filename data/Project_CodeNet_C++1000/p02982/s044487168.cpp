/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, d;
	cin >> n >> d;
	ld a[n][d];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < d; j++){
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int j = 0; j < n; j++){
		for (int i = j + 1; i < n; i++){
			ld x = 0; 
			for (int k = 0; k < d; k++){
				x += pow(a[i][k] - a[j][k], 2);
			}
			x = sqrt (x);
			if (floor(x) == ceil(x)){
				ans ++;
			}
		}
	}
	cout << ans << endl;
}
