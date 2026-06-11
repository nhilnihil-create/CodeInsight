#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string ans = "", S, T;
    cin >> N >> S >> T;
    for(int i = 0; i < N; i++) {
        ans += S.substr(i,1) + T.substr(i,1);
    }

    cout << ans << endl;
}