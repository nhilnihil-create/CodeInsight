/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	vector <pair <int, int>> v[n];
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		for (int j = 0; j < x; j++){
			int a, b;
			cin >> a >> b;
			v[i].push_back({a - 1, b});
		}
	}
	int mx = 0;
	int po = pow(2, n);
	int a[n];
	for (int i = 0; i < po; i++){
		int x = i, an = 0;
		for (int j = 0; j < n; j++){
			a[j] = x % 2;
			if (x % 2)
				an++;
			x /= 2;
		}
		bool f = true;
		for (int j = 0; j < n; j++){
			for (int k = 0; k < v[j].size(); k++){
				if (a[j] == 1){
					if (a[v[j][k].F] != v[j][k].S){
						f = false;
					}
				}
			}
		}
		if (f){
			mx = max(mx, an);
		}
	}
	cout << mx;
}
