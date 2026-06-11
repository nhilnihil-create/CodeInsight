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
	int n, k;
	cin >> n >> k;
	if (k > n)
		k = n;
	k = n - k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int sum = 0;
	for (int i = 0; i < k; i++) 
		sum += a[i];
	cout << sum;
}
