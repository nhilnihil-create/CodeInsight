#include <bits/stdc++.h>
using namespace std;

int N, K, A[200005];

bool possible(int maxLen)
{
	long long int cutsLeft = K;
	for(int i = 1; i <= N; i++)
	{
		if(A[i] % maxLen == 0)
			cutsLeft -= A[i] / maxLen;
			
		else
		{
			cutsLeft -= A[i] / maxLen;
			cutsLeft--;
		}
		
		cutsLeft++;
	}
	
	//printf("maxLen = %d, cutsLeft = %d\n", maxLen, cutsLeft);
	return (cutsLeft >= 0ll);
}

int binarySearch()
{
	int maxA = A[1];
	for(int i = 1; i <= N; i++)
		maxA = max(maxA, A[i]);
	
	int L = 1, R = maxA;
	int possAns = R;
	while(L <= R)
	{
		int M = L + (R - L) / 2;
		//printf("M = %d\n", M);
		if(possible(M))
		{
			R = M - 1;
			possAns = M;
		}
		
		else
			L = M + 1;
	}
	
	return possAns;
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
		
	printf("%d", binarySearch());
}
