#include<bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int a[n];
	int c = 0, mn = (int)2e9;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) if (mn > a[i]) {mn = a[i]; c++;}
	cout << c;

}

