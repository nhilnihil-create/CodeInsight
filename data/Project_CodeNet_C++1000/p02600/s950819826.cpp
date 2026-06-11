#include <bits/stdc++.h>
using namespace std;
int n;
string si, so;
int main() {
	cin >> n;
	if (n<600) cout << '8';
	else if (n<800) cout << '7';
	else if (n<1000) cout << '6';
	else if (n<1200) cout << '5';
	else if (n<1400) cout << '4';
	else if (n<1600) cout << '3';
	else if (n<1800) cout << '2';
	else cout << '1';
}