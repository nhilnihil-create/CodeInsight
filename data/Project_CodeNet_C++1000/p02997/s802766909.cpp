#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    int ma = (N - 1) * (N - 2) / 2;
    if (K > ma) {
        cout << -1 << endl;
        return 0;
    } else {
        vector<pair<int, int>> v;
        for (int i = 2; i <= N; i++) {
            v.push_back({1, i});
        }

        ma -= K;
        bool judge = 0;
        for (int i = 2; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (ma == 0) {
                    judge = 1;
                    break;
                }
                v.push_back({i, j});
                ma--;
            }
            if (judge)
                break;
        }

        cout << v.size() << endl;
        for (auto p : v) {
            cout << p.first << " " << p.second << endl;
            ;
        }
    }
}