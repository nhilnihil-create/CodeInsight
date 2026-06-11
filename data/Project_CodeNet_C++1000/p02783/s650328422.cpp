#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int h, a;
    cin >> h >> a;

    int ans = 0;
    while (h > 0) {
        h -= a;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
