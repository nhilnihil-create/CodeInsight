#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#ifdef LOCAL
    freopen("input.in" , "r" , stdin);
#endif
    int n;
    string s;
    cin >> n >> s;

    int R = 0 , G = 0 , B = 0;
    for (char &c : s) {
        R += c == 'R';
        G += c == 'G';
        B += c == 'B';
    }

    long long ans = 1ll * R * G * B;
    for (int i = 0 ;i < n ;i++) {
        for (int j = i + 1 ;j < n ;j++) {
            if (s[i] == s[j]) continue;
            int d = j - i;
            if (j + d >= n) continue;
            ans -= s[j + d] != s[i] && s[j + d] != s[j];
        }
    }

    cout << ans;
}