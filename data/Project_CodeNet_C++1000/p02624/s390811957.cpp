#include <bits/stdc++.h>
#include <iostream>

#define ll long long
using namespace std;

int main() {
	ll sm = 0;
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		int start = i;
		int end = n-(n%i);
		int cnt = (end-start)/i+1;
		sm += (ll)(start+end)*(ll)cnt/2;
	}
	cout << sm;
}
