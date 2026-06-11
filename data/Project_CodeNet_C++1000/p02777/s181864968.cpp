#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define rep(i, c) for(int i = 0; i < (int)c; i++)
const ll inf = ll(1e18)+1;

int main() {
	string s, t, u;
	int a, b;
	cin >> s >> t;
	cin >> a >> b;
	cin >> u;

	if (s == u) {
		a--;
	}
	else {
		b--;
	}

	cout << a <<' '<< b << endl;
	return 0;
}