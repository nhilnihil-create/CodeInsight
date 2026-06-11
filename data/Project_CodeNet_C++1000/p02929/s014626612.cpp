#include<cstdio>
#include<cstring>

const int MAX_N = 1e5, A = 1e9 + 7;
int n;
char s[2 * MAX_N + 1];
int dp[2 * MAX_N];

int main() {
    scanf("%d", &n);
    scanf("%s", s);

    int l = strlen(s);
    dp[0] = 1;
    if (s[0] == 'W') {
        printf("0\n");
        return 0;
    }
    for (int i = 1, cnt = 1; i < l; i++) {
        bool cj = cnt % 2;
        if ((s[i] == 'W' && !cj) || (s[i] == 'B' && cj)) {
            if (--cnt < 0) {
                printf("0\n");
                return 0;
            }
            dp[i] = static_cast<long>((cnt + 1)) * dp[i - 1] % A;
        }
        else if ((s[i] == 'W' && cj) || (s[i] == 'B' && !cj)) {
            if ((i - cnt) + 2 * cnt >= 2 * n) {
                printf("0\n");
                return 0;
            }
            cnt++;
            dp[i] = dp[i - 1];
        }
    }
    int per = 1;
    for (int i = 2; i <= n; i++) per = static_cast<long>(per) * i % A;
    int ans = static_cast<long>(per) * dp[l - 1] % A;
    printf("%d\n", ans);
    return 0;
}
