#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int N = S.size();
    vector<int> a(N + 1);
    for (int i = 0; i < N; i++) {
        if (S[i] == '<') a[i + 1] = a[i] + 1;
    }
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '>') a[i] = max(a[i], a[i + 1] + 1);
    }

    long long ans = 0;
    for (int x : a) ans += x;

    cout << ans << endl;
}