#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) continue;
        ans += i;
    }
    cout << ans << endl;
}