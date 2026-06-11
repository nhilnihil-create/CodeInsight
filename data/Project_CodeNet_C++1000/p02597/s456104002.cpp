#include <bits/stdc++.h>

using namespace std;

char s[200005];

int main() {
    int n;
    scanf("%d%s", &n, s);

    int totw = 0;
    int totr = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') totw++;
        else totr++;
    }

    int curw = 0;
    int res = 1e9;

    for (int i = 0; i <= n; i++) {
        int curr = n - i - totw + curw;
        res = min(res, max(curw, curr));

        if (i != n && s[i] == 'W') curw++;
    }

    printf("%d\n", res);
}
