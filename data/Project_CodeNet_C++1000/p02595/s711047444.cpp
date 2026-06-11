#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, D;
    cin >> N >> D;

    int ans = 0;
    D = pow(D, 2);
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if(pow(x, 2) + pow(y, 2) <= D) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}