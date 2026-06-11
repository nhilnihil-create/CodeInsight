/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int m, d;
	cin >> m >> d;
	int ans = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 10; j <= d; j++){
			string s = to_string(j);
			int mul = 1;
			for (int k = 0; k < 2; k++){
				mul *= (s[k] - '0');
			}
			if (mul == i && s[0] >= '2' && s[1] >= '2'){
				ans ++;
//				cout << i << ' ' << j << endl;
			}
		}
	}
	cout << ans << endl;
}
