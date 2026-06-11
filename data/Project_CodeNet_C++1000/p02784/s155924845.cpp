/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int a, n;
	cin >> a >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	cout << (sum >= a ? "Yes" : "No");
}
