#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
char s[N];

int main(void) {
    int n; scanf("%d", &n);
    scanf("%s", s + 1);
    int l = 1, r = n;
    int ans = 0;
    while (1) {
        while (s[l] == 'R' && l < r) ++l;
        while (s[r] == 'W' && l < r) --r;
        if (l == r) break;
        swap(s[l], s[r]);
        ans++;
    }
    printf("%d\n", ans);

    return 0;
}