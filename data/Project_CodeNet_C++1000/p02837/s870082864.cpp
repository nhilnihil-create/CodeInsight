//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N; cin >> N;
    vector<vector<pair<int, int>>> testimony(N);

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        for (int j = 0; j < a; j++) {
            int x, y; cin >> x >> y; x--;
            testimony[i].push_back(make_pair(x, y));
        }
    }

    int ans = 0;

    for (int bit = 0; bit < 1<<N; bit++) {

        bool flag = true;

        int tmp = 0;

        for (int i = 0; i < N; i++) {
            if (bit & 1<<i){
                tmp++;
                for (auto e : testimony[i]) {
                    if (e.second == 0) {
                        if (bit & 1<<e.first) flag = false;
                    }
                    if (e.second == 1) {
                        if (!(bit & 1<<e.first)) flag = false;
                    }
                }
            }
        }

        if (flag) ans = max(ans, tmp);
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}