#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 10000000000000

int N, K;
int H[305];

long long memo[305][305];
long long getMinPaint(int index, int remK)
{
    if (index >= N) return 0;
    if (memo[index][remK] != -1) return memo[index][remK];

    long long curAns = INF;
    for (int i = 0; i <= remK; i++)
    {
        curAns = min(curAns, getMinPaint(index + i + 1, remK - i) + max(0, H[index + i + 1] - H[index]));
    }
    return memo[index][remK] = curAns;
}

int main()
{
    scanf("%d%d", &N, &K);
    H[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", H + i);
    }

    memset(memo, -1, sizeof(memo));
    printf("%lld", getMinPaint(0, K));
}
