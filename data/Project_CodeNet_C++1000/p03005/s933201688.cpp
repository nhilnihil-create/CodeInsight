#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int ans = N - K;
    if (K == 1) ans = 0;
    cout << ans << endl;
    return 0;
}
