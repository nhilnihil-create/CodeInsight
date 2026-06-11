#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int N, A, B;
    cin >> N >> A >> B;
    long long int ans = 0;

    if ((A - B) % 2 == 0) {
        cout << (B - A) / 2 << endl;
    }
    else {
        if ((A - 1) < (N - B)) {
            ans += A - 1;
            ans++;
            ans += (B - A - 1) / 2;
        }
        else {
            ans += N - B;
            ans++;
            ans += (B - A - 1) / 2;
        }
        cout << ans << endl;
    }
}