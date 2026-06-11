#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, d;
	scanf("%d%d", &m, &d);
	int ans = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= d; j++){
			int x1 = j % 10, x2 = j / 10 % 10;
			if (x1 >= 2 && x2 >= 2 && x1 * x2 == i) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
