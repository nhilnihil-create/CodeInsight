#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << fixed << setprecision(0);
    string S, T;
    cin >> S >> T;

    int ans = T.size();

    for(int i = 0; i < S.size() - T.size() + 1; i++) {
        int cnt = 0;
        for(int j = 0; j < T.size(); j++) {
            if(S[i + j] != T[j])
                cnt++;
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}