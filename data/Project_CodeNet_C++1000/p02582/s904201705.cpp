#include <bits/stdc++.h>

using namespace std;

char s[1005];

int main() {
    scanf("%s", s);

    int res = 0;

    for (int i = 0; i < 3; i++) {
        if (s[i] == 'R') res++;
        else if (res) break;
    }

    printf("%d\n", res);
}
