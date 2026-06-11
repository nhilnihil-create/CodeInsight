#include <bits/stdc++.h>
#define cina(a, n) for (int i = 0; i < n; ++i){ cin >> a[i]; }
#define ll long long
#define ld long double

using namespace std;

int main () {
	
	int x, n, p[102];
	memset(p, 0, sizeof(p));
	cin >> x >> n;
	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		p[s] = 1;
	}
	int i = 0;
	while (1) {
		if (p[x-i] == 0) {
			cout << x-i;
			break;
		} else if(p[x+i] == 0) {
			cout << x+i;
			break;
		}
		i++;
	}
	return 0;
}