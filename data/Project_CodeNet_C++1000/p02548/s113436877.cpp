#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    int N;
    cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int A = i, B = N/A;
        if (A*B == N) {
            ans += B-1;
        }
        else {
            ans += B;
        }
    }
    cout << ans << endl;
}