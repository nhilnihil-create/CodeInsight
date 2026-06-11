#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

vector<int> q;
void build(int k, int l) {
    if (k == 0) {
        q[l] = 1;
        return;
    }
    int c = 1;
    while (c * 2 <= k) c *= 2;
//    cout << k << " " << l << " " << c << "\n";
    build(k - c, l);
    build(k - c, l + c);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    n--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = abs((int)s[i] - s[i + 1]);
    }
    q.resize(n);
    build(n - 1, 0);
    int ss = 0;
    for (int i = 0; i < n; i++) {
//        cout << q[i];
        ss += a[i] * q[i];
        ss %= 2;
    }
//    cout << "\n";
    if (ss == 1) {
        cout << 1 << "\n";
    } else {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) ok = false;
        }
        if (!ok) {
            cout << 0 << "\n";
        } else {
            for (int i = 0; i < n; i++) {
                ss += a[i] * q[i];
                ss %= 4;
            }
            cout << ss << "\n";
        }
    }

    return 0;
}