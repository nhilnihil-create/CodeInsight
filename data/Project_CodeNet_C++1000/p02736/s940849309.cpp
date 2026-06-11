#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int n;
int main() {
    scanf("%d%s", &n, s);
    int tag1 = 0, tag2 = 0, tag3 = 0;
    n--;
    for (int i = 0; i <= n; i++) {
        int now = s[i] - '0';
        if (now == 2) tag2 = 1;
        if ((i & n) == i) tag1 ^= now & 1, tag3 ^= ((now - 1) / 2) & 1;
    }
    return cout << (tag1 ? 1 : tag2 ? 0 : tag3 ? 2 : 0) << endl, 0;
}