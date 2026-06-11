#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int ans = T.length();
    for(int i = 0; i <= S.length() - T.length(); i++) {
        int d = 0;
        for(int j = 0; j < T.length(); j++) {
            if(T[j] != S[i + j]) {
                d++;
            }
        }
        ans = min(ans, d);
    }
    cout << ans;
}