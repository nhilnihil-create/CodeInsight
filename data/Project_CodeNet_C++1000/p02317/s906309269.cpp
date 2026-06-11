#include <cstdio>           // printf(), scanf()
#include <algorithm>        // lower_bound()

using namespace std;
static const int MAX_N = 100000;

int A[MAX_N + 1];
int L[MAX_N];
int n;

int
lis()
{
	L[0] = A[0];
	int length = 1;
	for (int i = 1; i < n; ++i)
	{
		if (L[length - 1] < A[i])
			L[length++] = A[i];
		else
			*lower_bound(L, L + length, A[i]) = A[i];
	}

	return length;
}

int
main(int argc, char** argv)
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &A[i]);

	printf("%d\n", lis());
	return 0;
}