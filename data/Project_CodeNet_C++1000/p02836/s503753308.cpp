#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    string S;
    cin >> S;
    string S_r = S;
    reverse(S_r.begin(), S_r.end());
    for(int i = 0; i < S.size() / 2; i++) {
        if(S[i] != S_r[i])
            ans++;
    }
    cout << ans << endl;
}