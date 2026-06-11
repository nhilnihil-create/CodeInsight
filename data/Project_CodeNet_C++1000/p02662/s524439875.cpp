#include <bits/stdc++.h>
using namespace std;

int A[3005];

long long memo[3005][3005];
const long long modConst = 998244353;

long long DP(int N, int S)
{
    if(S < 0)
        return 0;
        
    if(N == 0 && S == 0)
        return 1;
    
    if(N == 0)
        return 0;
        
    if(memo[N][S] != -1)
        return memo[N][S];
        
    long long putToBoth = DP(N - 1, S - A[N]);
    long long putToTOnly = DP(N - 1, S);
    long long putToNone = DP(N - 1, S);
    
    memo[N][S] = (putToBoth + putToTOnly + putToNone) % modConst;
    return memo[N][S];
}

int main()
{
    int N, S;
    scanf("%d%d", &N, &S);
    
    for(int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
        
    for(int i = 0; i < 3005; i++)
    {
        for(int j = 0; j < 3005; j++)
            memo[i][j] = -1;
    }
    
    long long ans = DP(N, S);
    printf("%lld", ans);
}
