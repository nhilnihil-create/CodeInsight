#include <bits/stdc++.h>
using namespace std;

char str[10];

int main() {
	scanf("%s", str + 1);
	int ans = 0, fans = 0;
	for (int i = 1; i <= 3; ++i) {
		if (str[i] == 'R') ans++;
		else fans = max(fans, ans), ans = 0;
	}
	fans = max(fans, ans);
	printf("%d\n", fans);
	return 0;
}