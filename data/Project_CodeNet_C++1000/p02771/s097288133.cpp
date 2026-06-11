#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if(a == b && c != a || b == c && a != b || c == a && b != c) printf("Yes\n");
    else printf("No\n");

    return 0;
}