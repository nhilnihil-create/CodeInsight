#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int h, n;
    cin >> h >> n;
    int tot = 0;
    for (int i = 0; i <= n - 1; i++) {
        int a;
        cin >> a;
        tot += a;
    }
    if (tot >= h) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}