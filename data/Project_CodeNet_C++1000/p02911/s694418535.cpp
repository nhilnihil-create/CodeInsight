#include "bits/stdc++.h"
using namespace std;
#define fst first
#define scd second
int a[100000];
signed main()
{
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	for(int i = 0, j; i < q; ++i)
	{
		scanf("%d", &j);
		++a[j - 1];
	}	
	for(int i = 0; i < n; ++i)
	{
		printf(a[i] > q - k ? "Yes\n" : "No\n");
	}
}
