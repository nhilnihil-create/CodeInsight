#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

void run() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> preW(n + 1), preR(n + 1);
    for (int i = 0; i < n; i++) {
        preW[i + 1] = preW[i] + (s[i] == 'W');
        preR[i + 1] = preR[i] + (s[i] == 'R');
    }
    int ans = preR[n];
    // rrr...wwww
    for (int i = 0; i < n; i++) {
        int L = preW[i + 1], R = preR[n] - preR[i + 1];
        ans = min(ans, max(L, R));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    run();
    return 0;
}
