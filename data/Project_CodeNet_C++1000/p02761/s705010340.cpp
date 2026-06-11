#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, char> > rules(m);
    for (size_t i = 0; i < m; i++) {
        int s;
        char c;
        cin >> s >> c;
        rules[i] = make_pair(s, c);
    }

    int ans = -1;
    for (size_t i = 0; i < 1000; i++) {
        string num = to_string(i);
        if (num.size() == n) {
            bool ok = true;
            for (size_t j = 0; j < m; j++) {
                if (num[rules[j].first-1] != rules[j].second) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = i;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
