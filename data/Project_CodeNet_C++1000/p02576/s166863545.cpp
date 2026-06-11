#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, X, T;
	scanf("%d%d%d", &N, &X, &T);
	
	if(N % X == 0)
		printf("%d", N / X * T);
		
	else
		printf("%d", (N / X + 1) * T);
}