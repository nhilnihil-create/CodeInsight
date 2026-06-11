#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, A[101], S = 0;
	scanf ("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		scanf ("%d", &A[i]);
		S += A[i];
	}

	int c = 0;
	for (int i = 0; i < N; i++){
		if (A[i] * 4 * M >= S) c++;
	}

	puts(c >= M ? "Yes" : "No");

	return 0;
}