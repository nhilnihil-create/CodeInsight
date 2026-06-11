#include <bits/stdc++.h>
using namespace std;

int memo[1000005], freq[1000005];
void sieve(int N)
{
	for(int i = 2; i <= N; i++)
		memo[i] = i;
		
	for(int i = 2; i * i <= N; i++)
	{
		if(memo[i] != i)
			continue;
			
		for(int j = i * i; j <= N; j += i)
			memo[j] = i;
	}
}

void primeFac(int x)
{
	int factor = 0, count = 0;
	while(x > 1)
	{
		if(memo[x] != factor)
		{
			freq[factor] += count;
			
			factor = memo[x];
			count = 1;
		}
		
		x /= memo[x];
	}
	
	freq[factor] += count;
}

int main()
{
	sieve(1000000);
	
	int N;
	scanf("%d", &N);
	
	int GCD = -1;
	for(int i = 1; i <= N; i++)
	{
		int Ai;
		scanf("%d", &Ai);
		primeFac(Ai);
		
		if(GCD == -1)
			GCD = Ai;
			
		else
			GCD = __gcd(GCD, Ai);
	}
	
	bool isPairwise = true;
	for(int i = 2; i <= 1000000; i++)
	{
		if(freq[i] >= 2)
		{
			isPairwise = false;
			break;
		}
	}
	
	if(isPairwise)
		printf("pairwise coprime");
		
	else if(GCD == 1)
		printf("setwise coprime");
		
	else
		printf("not coprime");
}
