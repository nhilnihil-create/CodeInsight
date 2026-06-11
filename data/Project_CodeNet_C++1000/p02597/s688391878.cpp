#include <iostream>
#include<bits/stdc++.h>
#include<cmath>
#include <algorithm> 
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,d;
	cin >> n;
	string s;
	cin >> s;
	long long red=0;
	long long white = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			red++;
		}
	}
	for (int i = 0; i < red; i++) {
		if (s[i] == 'W') {
			white++;
		}
	}
	cout << white;
	return 0;
}