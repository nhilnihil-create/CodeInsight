#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long K, ans = 0;
    string S;

    cin >> S;
    cin >> K;

    long tmp = 1;
    for (size_t i = 1; i < S.length(); i++) {
        if (S[i] == S[i-1]) {
            tmp++;
        }
        else {
            ans += floor(tmp/2);
            tmp = 1;
        }
    }
    ans += floor(tmp/2);
    ans *= K;

    bool flag = true;
    for (size_t i = 1; i < S.length(); i++) {
        if (S[i] != S[i-1]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << (long)floor(S.length() * K / 2) << endl;
        return 0;
    }

    if (S[0] == S[S.length()-1]) {
        long a = 1;
        long b = 1;
        for (size_t i = 1; i < S.length(); i++) {
            if (S[i] != S[i-1]) break;
            a++;
        }
        for (size_t i = S.length()-1; i > 0; i--) {
            if (S[i] != S[i-1]) break;
            b++;
        }
        ans -= (long)(floor(a/2) + floor(b/2) - floor((a+b)/2)) * (K-1);
    }

    cout << ans << endl;

    return 0;
}