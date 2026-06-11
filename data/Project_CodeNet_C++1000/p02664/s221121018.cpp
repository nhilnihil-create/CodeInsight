#include <bits/stdc++.h>
using namespace std;

char s[200055];

int main() {
    scanf("%s", s);

    int n = strlen(s);

    for (int i = 0; i < n; i++) if (s[i] == '?') {
        s[i] = 'D';
    }

    puts(s);

    return 0;
}
