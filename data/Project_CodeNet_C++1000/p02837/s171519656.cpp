#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L


int main() {
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> persons(N);
    for (int i = 0; i < N; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            x--;
            persons[i].push_back({ x, y });
        }
    }
    int mx = 0;
    for (int b = 0; b < (1 << N); b++) {
        vector<bool> honest(N);
        bool ok = true;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (b & (1 << i)) {
                honest[i] = true;
                cnt++;
            }
        }
        for (int p = 0; p < N; p++) {
            for (int s = 0; s < (int)persons[p].size(); s++) {
                if (honest[p] && honest[persons[p][s].first] != persons[p][s].second) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
            mx = max(mx, cnt);
    }
    cout << mx;
    return 0;
}