#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	if (S.back()=='s') {
		S+="es";
	} else {
		S+="s";	
	}
	cout << S << endl;
	return 0;
}
