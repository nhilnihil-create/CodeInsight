#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

char s[1000010];

inline int C(int n, int m) { return (n & m) == m; }

int main() {
    int n;
    scanf("%d%s", &n, s + 1);
    if(n == 1) putchar(s[1]), puts("");
    else {
        --n;
        int find1 = 0;
        for(int j = 1; j <= n; j++)
            s[j] = abs(s[j] - s[j + 1]), find1 |= s[j] == 1;
        if(!find1) for(int i = 1; i <= n; i++) s[i] >>= 1;
        find1 ^= 1;
        int t = 0;
        for(int j = 1; j <= n; j++) t ^= C(n - 1, j - 1) * (s[j] & 1);
        cout << (int(t) << find1) << endl;
    }
    return 0;
}
