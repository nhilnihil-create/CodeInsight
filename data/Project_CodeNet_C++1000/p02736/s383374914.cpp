#include <stdio.h>
#include <math.h>

const int maxn=1e6+10;
int n,a[maxn],dp[maxn],ans;

int C(int n, int m) {return (n|m)==n;}

int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;++i) {
        scanf("%1d", &a[i]);
    }
    if (n==1) {
        printf("%d\n", a[1]);
        return 0;
    }
    int flag=1;
    for (int i=1;i<=n-1;++i) {
        dp[i] = abs(a[i]-a[i+1]);
        if (dp[i] == 1) flag=0;
    }
    if (flag) {
        for (int i=1;i<=n-1;++i) {
            dp[i] /= 2;
        }
    }
    else {
        for (int i=1;i<=n-1;++i) {
            dp[i] %= 2;
        }
    }
    for (int i=1;i<=n-1;++i) {
       if (dp[i]) ans ^= C(n-2,i-1);
    }
    if (flag) ans *= 2;
    printf("%d\n", ans);
    return 0;
}