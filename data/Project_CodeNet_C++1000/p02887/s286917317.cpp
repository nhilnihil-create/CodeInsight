#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    int num = 1;
    rep(i, n) {
        if (i == 0) continue;
        if (s[i] != s[i-1]) num++;
    }
    printf("%d\n", num);
}