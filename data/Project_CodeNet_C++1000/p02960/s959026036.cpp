#include <cstdio>
#include <cstring>

#define MOD 1000000007

using ll = long long;

int main() {
    char S[100005];
    scanf("%s\n", S);
    ll N = strlen(S);

    ll mod13[13];
    mod13[0] = 1;
    int exponent = 1;

    for (int i = 0; i < N; i++) {
        ll mod13_buf[13] = {0};
        int c = (S[N - i - 1] == '?') ? -1 : S[N - i - 1] - '0';
        if (c == -1) {
            for (int n = 0; n < 10; n++) {
                int m = n * exponent % 13;
                for (int r = 0; r < 13; r++) {
                    mod13_buf[(r + m) % 13] += mod13[r];
                }
            }
        } else {
            for (int r = 0; r < 13; r++) {
                int m = c * exponent % 13;
                mod13_buf[(r + m) % 13] += mod13[r];
            }
        }
        exponent = exponent * 10 % 13;
        for (int j = 0; j < 13; j++) {
            mod13[j] = mod13_buf[j] % MOD;
        }
    }
    printf("%lld\n", mod13[5]);
}
