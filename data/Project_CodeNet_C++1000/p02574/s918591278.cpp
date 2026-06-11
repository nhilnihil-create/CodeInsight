#include <bits/stdc++.h>
using namespace std;

vector<int> memo[1000005];
int cnt[1000005];
int arr[1000005];

bool isPrime[1000005];
void sieve1(int N)
{
	for(int i = 2; i <= 1000000; i++)
		isPrime[i] = true;
		
	for(int i = 2; i * i <= 1000000; i++)
	{
		if(isPrime[i])
		{
			//printf("i = %d\n", i);
			for(int j = i * i; j <= 1000000; j += i)
				isPrime[j] = false;
		}
	}
}

void sieve(int N)
{
	for(int i = 2; i <= 1000000; i++)
	{
		if(isPrime[i])
		{
			int idx = lower_bound(arr + 1, arr + N + 1, i) - arr, idx3 = upper_bound(arr + 1, arr + N + 1, i) - arr;
			
			cnt[i] += (idx3 - idx);
					
			memo[i].push_back(i);
			
			if(i > 1000)
				continue;
			
			for(int j = i * i; j <= 1000000; j += i)
			{
				int idx1 = lower_bound(arr + 1, arr + N + 1, j) - arr, idx2 = upper_bound(arr + 1, arr + N + 1, j) - arr;
				
				if(isPrime[i])
				{
					cnt[i] += (idx2 - idx1);
				}
				
				if(j / i != i && isPrime[j / i])
					cnt[j / i] += (idx2 - idx1);
					
				memo[j].push_back(i);
			}
		}
	}
	
	
}


bool isPairwise()
{
	for(int i = 2; i <= 1000000; i++)
	{
		if(cnt[i] >= 2)
			return false;
	}
	
	return true;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int GCD = -1;
	for(int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);
		arr[i] = num;
		
		if(GCD == -1)
			GCD = num;
			
		else
			GCD = __gcd(GCD, num);
	}
	sort(arr + 1, arr + N + 1);
	
	sieve1(N);
	sieve(N);
	
	if(isPairwise())
		printf("pairwise coprime");
		
	else if(GCD == 1)
		printf("setwise coprime");
		
	else
		printf("not coprime");
}
