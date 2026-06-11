/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int f(int n) {
	if (n == 0)
		return 0;
	return (2 * f(n / 2)) + 1;
}

int32_t main(){
	int n;
	cin >> n;
	cout << f(n);
}
