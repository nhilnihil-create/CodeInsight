#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h, w, n;
	cin >> h >> w >> n;
	if(h > w) swap(h, w);
	printf("%d\n", (n + w - 1) / w);
	return 0;
}