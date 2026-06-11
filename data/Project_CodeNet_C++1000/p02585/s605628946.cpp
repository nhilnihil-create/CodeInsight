#include <bits/stdc++.h>
using namespace std;

long long N, K, P[5005], C[5005];
vector<long long> scores[5005];

bool visited[5005];

int start = 0;
void dfs(int src)
{
	if(visited[src])
		return;
		
	visited[src] = true;
	if(scores[start].empty())
		scores[start].push_back(C[P[src]]);
		
	else
		scores[start].push_back(scores[start].back() + C[P[src]]);
		
	dfs(P[src]);
}

int main()
{
	scanf("%lld%lld", &N, &K);
	for(long long i = 1; i <= N; i++)
	{
		scanf("%lld", &P[i - 1]);
		P[i - 1]--;
	}
	
	for(long long i = 1; i <= N; i++)
		scanf("%lld", &C[i - 1]);
		
	for(long long int i = 0; i < N; i++)
	{
		for(long long int j = 0; j < N; j++)
			visited[j] = false;
		
		start = i;
		dfs(i);
	}
	
	/*for(long long int i = 0; i < N; i++)
	{
		for(long long int j = 0; j < (long long)(scores[i].size()); j++)
			printf("%lld ", scores[i][j]);
			
		printf("\n");
	}*/
	
	//printf("\n");
	
	long long grandMax = 0;
	for(long long int i = 0; i < N; i++)
	{
		long long maxScore = scores[i][0];
		if(K <= (long long)(scores[i].size()) )
		{
			maxScore = scores[i][0];
			for(long long int j = 1; j <= K; j++)
				maxScore = max(maxScore, scores[i][j - 1]);
				
			//printf("i = %lld, maxScore = %lld\n", i, maxScore);
		}
		
		else
		{
			if(scores[i].back() >= 0)
			{
				for(long long j = 0; j < (long long)(scores[i].size()); j++)
				{
					long long numCycles = (K - j - 1) / (long long)(scores[i].size());
					maxScore = max(maxScore, scores[i][j] + numCycles * scores[i].back());
				}
			}
			
			else
			{
				long long maximum = scores[i][0];
				for(long long j = 0; j < (long long)(scores[i].size()); j++)
					maximum = max(maximum, scores[i][j]);
				
				maxScore = maximum;
			}
		}
		
		if(i != 0)
			grandMax = max(grandMax, maxScore);
			
		else
			grandMax = maxScore;
	}
	
	printf("%lld", grandMax);
}
