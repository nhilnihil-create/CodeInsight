#include <bits/stdc++.h>

using namespace std;

int ps[3][4005];
char s[4005];

int f(char c) {
	if (c == 'R') return 0;
	else if (c == 'G') return 1;
	return 2;
}

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	
	for (int i = 0; i < n; i++) {
		ps[f(s[i])][i]++;
		
		if (i - 1 >= 0) {
			for (int j = 0; j < 3; j++) {
				ps[j][i] += ps[j][i - 1];
			}
		}
	}
	
	long long res = 0;
	
	for (int i = 1; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j]) continue;
			int idx = 3;
			idx -= f(s[i]) + f(s[j]);
			long long add = ps[idx][i - 1];
			int diff = j - i;
			if (i - diff >= 0 && f(s[i - diff]) == idx) add--;
			
			res += add;
		}
	}
	
	printf("%lld\n", res);
}
