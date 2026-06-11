#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005
int A[N], n;
int main()
{
	scanf("%d", &n);
	int s = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]), s ^= A[i];
	for (int i = 1; i <= n; i++)
		printf("%d%c", s ^ A[i], i == n ? 10 : 32);
}