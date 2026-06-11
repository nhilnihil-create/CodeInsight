#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h, a;
	scanf("%d%d", &h, &a);
	int count = 0;
	while (h > 0) {
		count++;
		h -= a;
	}
	printf("%d\n", count);
	return 0;
}