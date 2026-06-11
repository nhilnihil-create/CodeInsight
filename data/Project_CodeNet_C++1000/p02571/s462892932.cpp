#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    int ans = T.length();
    for (int i = 0; i <= (int)(S.length() - T.length()); ++i) {
        int count = 0;
        for (int j = 0; j < (int)T.length(); ++j) {
            if (S[i + j] != T[j]) count++;
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
    return 0;
}