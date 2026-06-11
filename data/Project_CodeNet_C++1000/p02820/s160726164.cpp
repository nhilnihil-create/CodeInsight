//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N, K; cin >> N >> K;
    map<char, int> score;
    cin >> score['s'] >> score['p'] >> score['r'];
    string T; cin >> T;

    int ans = 0;

    for (int i = 0; i < K; i++) {
        int j = i;
        ans += score[T[j]];
        char before = T[j];
        bool ok = false;

        j += K;

        while (j < N) {
            if (T[j] != before) {
                ans += score[T[j]];
                ok = false;
            }
            else {
                if (ok) ans += score[T[j]];
                ok = !ok;
            }
            before = T[j];
            j += K;
        }
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}