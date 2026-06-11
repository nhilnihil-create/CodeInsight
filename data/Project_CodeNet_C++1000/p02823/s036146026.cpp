#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 N, A, B;
int main()
{
    scanf("%lld%lld%lld", &N, &A, &B);
    printf("%lld\n", (B-A)&1?min(A, N+1-B)+(B-A-1)/2:(B-A)/2);
    return 0;
}