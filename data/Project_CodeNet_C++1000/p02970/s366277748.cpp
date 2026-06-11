#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, d;
    cin >> n >> d;

    int now = 0;
    int ans = 0;
    while (now < n) {
        now += 2 * d + 1;
        ans++;
    }

    cout << ans << endl;
    return 0;
}
