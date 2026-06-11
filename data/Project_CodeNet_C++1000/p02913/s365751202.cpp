#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int N;
    string S;
    cin >> N >> S;
    for(int i = 1; i < N; i++) {
        int len = 1;
        for(int j = 0; i + j < N; j++) {
            if(S[j] == S[i + j]) {
                ans = max(ans, min(i, len));
                len++;
            } else
                len = 1;
        }
    }
    cout << ans << endl;
}