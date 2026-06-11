#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < max(a, b); i++) cout << min(a, b);
    return 0;
}