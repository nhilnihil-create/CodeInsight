#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt[2] = {0};
    vector<int> a(s.size());
    rep(i, s.size()) {
        if (s[i] == 'R')
            cnt[i % 2]++;
        else {
            a[i - 1] += cnt[1 - i % 2];
            a[i] += cnt[i % 2];
            cnt[0] = cnt[1] = 0;
        }
    }

    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == 'L')
            cnt[i % 2]++;
        else {
            a[i + 1] += cnt[1 - i % 2];
            a[i] += cnt[i % 2];
            cnt[0] = cnt[1] = 0;
        }
    }

    rep(i, a.size()) {
        if (i != 0)
            cout << " ";
        cout << a[i];
    }
    cout << endl;

    return 0;
}