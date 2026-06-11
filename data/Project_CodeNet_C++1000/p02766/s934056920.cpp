#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(void) {
	ll n,k;

	cin >> n>>k;

	int i = 1;
	while (1) {
		if (n < pow(k,i)) {
			break;
		}
		else {
			i++;
		}
	}

	cout << i << endl;
	return 0;
}