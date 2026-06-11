#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    int ans = 0;
    int ketasu = 1;
    for (size_t i = 1; i <= n; i++) {
        if (i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000) ketasu++;
        if (ketasu%2 == 1) ans++;
    }

    cout << ans << endl;
    return 0;
}
