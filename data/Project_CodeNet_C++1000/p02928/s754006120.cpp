/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 1000 * 1000 * 1000 + 7;

int32_t main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int su1 = 0, su2 = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			su1 += (a[i] > a[j]);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			su2 += (a[i] > a[j]);
		}
	}
	su1 %= M;
	su2 %= M;
	int x = (su1 * k) % M;
	int y = (k) * (k - 1);
	y /= 2;
	y %= M;
	y *= su2;
	y %= M;
	cout << (x + y) % M; 
}
