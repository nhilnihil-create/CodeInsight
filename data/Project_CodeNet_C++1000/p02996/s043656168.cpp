#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int N;
void solve() {
    cin >> N;
    vector<P> s(N);
    int last = -1;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        s[i] = P(b, a);
    }
    sort(s.begin(), s.end());
    int idx = 0;
    for (P p : s) {
        idx += p.second;
        if (p.first < idx) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    solve();
    return 0;
}
