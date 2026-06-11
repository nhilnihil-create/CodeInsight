#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int l = max(a, b);
    int s = min(a, b);
    int ans = 0;
    for (int i = 0; i < l; i++)ans += s*pow(10, i);
    cout << ans << endl;
    return 0;
}