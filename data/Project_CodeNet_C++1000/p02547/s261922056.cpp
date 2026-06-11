#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i = m; i < N; i++)
#define INF (INT64_MAX /2)


























int main() {
    int N;
    cin >> N;
    int count = 0;
    bool a = false;
    rep(i, 0, N) {
        int d, e;
        cin >> d >> e;
        if (d == e) count++;
        else count = 0;
        if (count == 3) a = true;
    }

    if (a) cout << "Yes" << endl;
    else cout << "No" << endl;
}