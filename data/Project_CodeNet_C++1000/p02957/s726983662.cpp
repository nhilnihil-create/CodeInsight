#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll int a, b;
	cin >> a >> b;
	if((a+b)%2==0) {
		cout << (a+b)/2 << endl;
	}else{
		cout << "IMPOSSIBLE";
	}
}

