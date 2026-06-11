#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string before, now;
    long long ans = 0;
    for (long long i = 0; i < S.length(); i++) {
        now += S[i];
        if (now != before) {
            before = now;
            now = "";
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
