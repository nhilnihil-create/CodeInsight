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
	int a, b, k;
	cin >> a >> b >> k;
	if (k <= a){
		cout << a - k << ' ' << b;
	}else{
		cout << "0 " << max(0ll, (a + b) - k); 
	}
}
