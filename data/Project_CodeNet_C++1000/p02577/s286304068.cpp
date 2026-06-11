#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
 
int main() {
	FASTIO

	string s;
	cin >> s;
	int sum = 0;
	for(char c : s) sum += c-'0';
	cout << ((sum%9 == 0) ? "Yes\n" : "No\n");
	
	return 0;
}