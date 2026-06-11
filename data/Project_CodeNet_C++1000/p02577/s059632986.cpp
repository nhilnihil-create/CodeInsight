#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = 0;
	for (int i = 0; i < (int) s.size(); ++i) {
		n += s[i] - '0';
	}
	if (n % 9 == 0)
		puts("Yes");
	else
		puts("No");

	return 0;
}

