/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int l, r;
	cin >> l >> r;
	if (r - l <= 10000){
		int mn = 100000000;
		for (int i = l; i <= r; i++){
			for (int j = i + 1; j <= r; j++){
				mn = min(mn, (i * j) % 2019);
			}
		}
		cout << mn;
	}else{
		cout << 0;
	}
}
