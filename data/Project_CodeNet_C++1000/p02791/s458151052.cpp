#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int N, cnt = 1; cin >> N;
    int m = 1000000;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x < m) {
            m = x;
            if (i == 0) continue;
            cnt++;
        }
    }
    cout << cnt << endl;
}