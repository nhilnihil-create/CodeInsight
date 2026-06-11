#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int s[N], c[N];
    for (int i = 0; i < M; i++) cin >> s[i] >> c[i];

    int num[N];
    for (int i = 0; i < N; i++) num[i] = -1;
    for (int i = 0; i < M; i++) {
        if ((s[i] == 1) && (c[i] == 0) && (N > 1)) {
            cout << -1 << endl;
            return 0;
        }
        else if ((num[s[i] - 1] != -1) && (num[s[i] - 1] != c[i])) {
            cout << -1 << endl;
            return 0;
        }
        else {
            num[s[i] - 1] = c[i];
        }
    }
    string ans = "";
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (num[i] == -1 || num[i] == 0) {
                if (N == 1) ans += "0";
                else ans += "1";
            }
            else {
                ans += to_string(num[i]);
            }
        }
        else {
            if (num[i] == -1) {
                ans += "0";
            }
            else {
                ans += to_string(num[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}