#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    int ans = 0;
    int len = S.length() - 1;
    for (int i = 0; i <= len / 2; i++) {
        if (S[i] != S[len - i]) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}