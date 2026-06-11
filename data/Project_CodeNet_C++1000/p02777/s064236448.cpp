#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t, u;
    cin >> s >> t;
    int a, b;
    scanf("%d%d", &a, &b);
    cin >> u;

    if (s == u) a--;
    if (t == u) b--;

    printf("%d %d\n", a, b);
}
