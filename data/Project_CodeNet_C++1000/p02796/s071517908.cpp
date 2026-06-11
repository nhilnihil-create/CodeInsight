#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<pair<int, int>> p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        p.push_back(make_pair(x + l, x - l));
    }

    int cur = -1000000000;
    int ans = 0;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        if (p.at(i).second >= cur) {
            ans++;
            cur = p.at(i).first;
        }
    }

    cout << ans << endl;
}
