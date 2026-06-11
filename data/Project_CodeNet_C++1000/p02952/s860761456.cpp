#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int digits(int x) {
    int result = 0;
    while (x) {
        result++;
        x /= 10;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (digits(i) % 2 == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
