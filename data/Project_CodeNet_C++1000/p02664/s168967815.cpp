#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

char str[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++) cout << ((str[i] == '?') ? 'D' : str[i]);
	cout << "\n";
	
	return 0;
}
