#include <iostream>
#include <cstdio>
using namespace std;

int n;
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			for (k = 0; ; k++) {
				if (((i ^ j) >> k) & 1) break;
			}
			printf("%d ", k + 1);
		}
		puts("");
	}
    return 0;
}