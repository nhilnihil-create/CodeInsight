#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define rep(i, c) for(int i = 0; i < (int)c; i++)
const ll inf = 1000000007;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) {
		cin >> a[i];
	}
	
	rep(i, n) {
		if (a[i]%2==0 && (a[i] % 3 != 0 && a[i] % 5 != 0)) {
			cout << "DENIED" << endl;
			return 0;
		}
	}

	cout << "APPROVED" << endl;
	return 0;
}