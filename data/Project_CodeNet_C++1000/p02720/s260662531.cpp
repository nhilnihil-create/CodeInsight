#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int K;

void go(int d, long long u)
{
	if (d == 0){
		if (--K == 0){
			printf ("%lld\n", u);
			exit(0);
		}
		return;
	}

	int v = u % 10;
	for (int k = v - 1; k <= v + 1; k++) if (0 <= k && k <= 9) go(d - 1, u * 10 + k);
}

int main()
{
	scanf ("%d", &K);
	for (int l = 1;; l++) for (int s = 1; s <= 9; s++) go(l - 1, s);

	return 0;
}