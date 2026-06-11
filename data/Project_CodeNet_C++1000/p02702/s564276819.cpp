#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    cin >> S;
    int i, T[200010], v[2050] = {0}, num = 0, N = S.size(), digit = 1;
    T[N] = 0;
    for (i = N - 1; i >= 0; --i) {
        num = (num + digit * (S[i] - '0')) % 2019;
        T[i] = num;
        digit = digit * 10 % 2019;
    }
    v[0] = 1;
    for (i = 0; i < N; ++i) {
        v[T[i]]++;
    }
    int ans = 0;
    for (i = 0; i < 2020; ++i) {
        if (v[i] == 0) {
            continue;
        }
        ans += v[i] * (v[i] - 1) / 2;
    }
    printf("%d\n", ans);

    return 0;
}
