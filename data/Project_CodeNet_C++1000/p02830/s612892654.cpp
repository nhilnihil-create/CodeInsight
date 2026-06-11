#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<char> s(n), t(n), u(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> t.at(i);
    }

    for (int i = 0; i < n; i++) {
        u.at(2 * i) = s.at(i);

        u.at(2 * i + 1) = t.at(i);
    }
    for (int i = 0; i < n * 2; i++) {
        cout << u.at(i);
    }
    cout << endl;
    return 0;
}