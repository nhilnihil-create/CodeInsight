#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int h, n;
    cin >> h >> n;
    long long asum = 0;
    for (size_t i = 0; i < n; i++) {
        int a;
        cin >> a;
        asum += a;
    }

    if (asum >= h) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
