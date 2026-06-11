#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.length();
    vector<long long> x(N + 1);
    x[0] = 0;

    // x[0] op(s[0]) x[1]
    for (int i = 0; i < N; ++i) {
        if (s[i] == '<')
            x[i + 1] = x[i] + 1;
        else
            x[i + 1] = 0;
    }

    // x[N - 1] op(s[N - 1]) x[N]
    for (int i = N - 1; i >= 0; --i) {
        if (s[i] == '>')
            x[i] = max(x[i], x[i + 1] + 1);
    }

    long long ans = 0;
    for (int i = 0; i <= N; ++i)
        ans += x[i];
    cout << ans << endl;
}
