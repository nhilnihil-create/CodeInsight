#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define rep(i, c) for(int i = 0; i < (int)c; i++)
const ll inf = ll(1e18)+1;

int main() {
	string s;
	cin >> s;

	int a = s.size();

	rep (i,a) {
		s[i] = 'x';
	}

	cout << s<< endl;
	return 0;
}