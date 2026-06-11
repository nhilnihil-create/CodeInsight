/*
P135
AOJ 0189 Convenient Location
*/

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <functional>
#include <string.h>
#include <cmath>

using namespace std;

const int MAXN = 15;

int d[MAXN][MAXN];
int M, N;

bool read()
{
    scanf("%d", &M);
    if(M==0) return false;
    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++)
        {
            d[i][j] = 1<<20;
        }
        d[i][i] = 0;
    }
    N = 0;
    int s, e, m;
    for(int i=0; i<M; ++i){
        scanf("%d%d%d", &s, &e, &m);
        d[s][e] = m;
        d[e][s] = m;
        N = max(N, s);
        N = max(N, e);
    }
    return true;
}

void floyd(int n)
{
    for(int k=0; k<n; ++k)
    for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
    {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
}
void solve()
{
    floyd(N+1);
    int dmin = 1<<20, idx = 0;
    for(int i=0; i<N; ++i){
        int dis = 0;
        for(int j=0; j<=N; ++j)
            dis += d[i][j];
        if(dis < dmin) dmin = dis, idx = i;
    }
    printf("%d %d\n", idx, dmin);

}

int main()
{
    while(read()){
        solve();
    }
}