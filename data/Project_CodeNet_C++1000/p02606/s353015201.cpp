#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int L, R, d;
    cin >> L >> R >> d;
    int ans = 0;
    for (int i = L; i <= R; i++) {
        if (i % d == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
