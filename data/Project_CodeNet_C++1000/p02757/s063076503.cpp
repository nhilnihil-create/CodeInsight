#include <bits/stdc++.h>

using namespace std;

char s[200005];
long long ps[200005], pw[200005];

unordered_map <long long, int> cnt;

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    scanf("%s", s);

    if (p == 2 || p == 5) {
        long long res = 0;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ((s[i] - '0') % p == 0) cnt++;
            res += cnt;
        }
        return 0 * printf("%lld\n", res);
    }


    pw[0] = 1LL;
    for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 10 % p;

    for (int i = n - 1; i >= 0; i--) {
        ps[i] = (pw[n -  1 - i] * (s[i] - '0') + ps[i + 1]) % p;
    }

    long long res = 0;
    cnt[0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        res += cnt[ps[i]];
        cnt[ps[i]]++;
    }

    printf("%lld\n", res);
}
