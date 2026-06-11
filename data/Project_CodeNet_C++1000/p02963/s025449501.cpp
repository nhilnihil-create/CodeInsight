#include <bits/stdc++.h>
#define N 10099
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define LL long long
using namespace std;
int n;
LL S;
int main()
{
    cin >> S;
    LL t = sqrt(S);
    t++;
    if (t > 1000000000)
        t = 1000000000;
    LL cha = t * t - S;
    printf("0 0 %lld 1 %lld %lld\n", t, cha, t);
    return 0;
}
