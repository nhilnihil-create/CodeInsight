#include <iostream>
using namespace std;

#define MAX 1000000
#define INF (1<<24)
int n[100000],M;

int dp[1000005];
int od[1000005];

int main()
{
	for(M=1; ; M++)
	{
		int v=M*(M+1)*(M+2)/6;
		if(v>MAX) break;
		n[M]=v;
	}



	for(int i=0; i<=MAX; i++)
	{
		dp[i]=INF;
		od[i]=INF;
	}

	dp[0]=od[0]=0;

	for(int i=1; i<M; i++)
	for(int j=0; j<=MAX; j++) 
	{
		if(j+n[i] > MAX) break;
		if(dp[j]!=INF)
		{
			dp[j+n[i]]=min(dp[j+n[i]], dp[j]+1);
		}
		if(od[j]!=INF&&n[i]%2==1)
		{
			od[j+n[i]]=min(od[j+n[i]], od[j]+1);
		}
	}
	int N;
	while(cin >> N, N)
	{

		cout << dp[N] << " " << od[N] << endl;
	}


}