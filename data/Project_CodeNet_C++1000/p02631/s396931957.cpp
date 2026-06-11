#include<bits/stdc++.h>
using namespace std;

long long n, i, x, ans;

int main()
{
    scanf("%lld", &n);
    long long a[n];
    for (i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ans ^= a[i];
    }
    for (i = 0; i < n; i++) {
        if (i == 0) printf("%lld", ans^a[i]);
        else printf(" %lld", ans^a[i]);
    }
    printf("\n");
    return 0;
}